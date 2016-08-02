#ifndef MAINWIND_H
#define MAINWIND_H

#include <QMainWindow>
#include <QTreeWidgetItem>
#include <QXmlStreamReader>
#include <QTreeWidget>
#include <QFile>
#include <QMessageBox>

class MainWindow : public QMainWindow
{
    Q_OBJECT
public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

    bool readFile(const QString &fileName);
private:
    void readBookindexElement();
    void readEntryElement(QTreeWidgetItem *parent);
    void readPageElement(QTreeWidgetItem *parent);
    void skipUnknownElement();

    QTreeWidget *treeWidget;
    QXmlStreamReader reader;
};

#endif // MAINWIND_H
