#include "network.h"

class NetWorkr::Private
{
public:
    Private(NetWorkr *q):
        manager(new QNetworkAccessManager(q))
    {

    }

    QNetworkAccessManager *manager;
};

NetWorkr *NetWorkr::instance()
{
    static NetWorkr netWorker;
    return &netWorker;
}

NetWorkr::NetWorkr(QObject *parent):
    QObject(parent),
    d(new NetWorkr::Private(this))
{
    connect(d->manager,&QNetworkAccessManager::finished,
            this,&NetWorkr::finished);
}

NetWorkr::~NetWorkr()
{
    delete d;
    d = 0;
}

void NetWorkr::get(const QString &url)
{
    d->manager->get(QNetworkRequest(QUrl(url)));
}
