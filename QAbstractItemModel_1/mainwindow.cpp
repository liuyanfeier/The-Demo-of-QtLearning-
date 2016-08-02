#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

CurrencyModel::CurrencyModel(QObject *parent)
    : QAbstractTableModel(parent)
{

}

//保存的是每种货币相对美元的汇率，而需要显示的是它们两两之间的汇率
//rowCount()和columnCount()用于返回行和列的数目
int CurrencyModel::rowCount(const QModelIndex &parent) const
{
    return currencyMap.count();
}

int CurrencyModel::columnCount(const QModelIndex &parent) const
{
    return currencyMap.count();
}

//返回列名
QVariant CurrencyModel::headerData(int section, Qt::Orientation orientation, int role) const
{
    if(role != Qt::DisplayRole)
    {    //判断这个角色是不是用于显示的
        return QVariant();
    }
    return currencyAt(section);
}

QString CurrencyModel::currencyAt(int offset) const
{
    return (currencyMap.begin()+offset).key();
}

void CurrencyModel::setCurrencyMap(const QMap<QString, double> &map)
{
    beginResetModel();
    currencyMap = map;
    endResetModel();
}

QVariant CurrencyModel::data(const QModelIndex &index, int role) const
{
    //返回一个单元格的数据
    //它有两个参数：第一个是QModelIndex，也就是单元格的位置；第二个是role，也就是这个数据的角色。
    if(!index.isValid()){
        return QVariant();
    }

    if(role == Qt::TextAlignmentRole){
        //文本对齐方式
        return int(Qt::AlignRight | Qt::AlignVCenter);
    }
    else if(role == Qt::DisplayRole || role == Qt::EditRole){
        QString rowCurrency = currencyAt(index.row());
        QString columnCurrency = currencyAt(index.column());
        if(currencyMap.value(rowCurrency) == 0.0){
            return "####";
        }
        double amount = currencyMap.value(columnCurrency)
                / currencyMap.value(rowCurrency);
        return QString("%1").arg(amount,0,'f',4);
    }
    return QVariant();
}

//通过flags函数来判断该数据是否允许编辑
Qt::ItemFlags CurrencyModel::flags(const QModelIndex &index) const
{
    Qt::ItemFlags flags = QAbstractItemModel::flags(index);
    if(index.row() != index.column()){
        flags |= Qt::ItemIsEditable;
    }
    //flags |= Qt::ItemIsEditable;
    return flags;
}

//将委托获得的用户输入的新的数据保存到模型中
bool CurrencyModel::setData(const QModelIndex &index, const QVariant &value, int role)
{
    if(index.isValid() && index.row() != index.column()
            && role == Qt::EditRole){
        QString columnCurrency = headerData(index.column(),
                                            Qt::Horizontal,
                                            Qt::DisplayRole).toString();
        QString rowCurrency = headerData(index.row(),
                                         Qt::Vertical,
                                         Qt::DisplayRole).toString();
        currencyMap.insert(columnCurrency,
                           value.toDouble() * currencyMap.value(rowCurrency));
        emit dataChanged(index,index);
        //模型需要通知视图，数据发生了变化，所以需要发出dataChanged信号
        return true;
    }
    return false;
}
