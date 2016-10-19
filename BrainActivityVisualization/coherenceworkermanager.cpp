#include "coherenceworkermanager.h"
#include "coherenceworker.h"

CoherenceWorkerManager::CoherenceWorkerManager()
{

}

CoherenceWorkerManager::~CoherenceWorkerManager()
{

}

const QList<QVector<QVector<QVector<float> > > > CoherenceWorkerManager::getResults()
{
    return m_matrix;
}

void CoherenceWorkerManager::compute()
{
    m_matrix.append(staticRun());
}

const QVector<QVector<QVector<float> > > CoherenceWorkerManager::staticRun()
{
    CoherenceWorker tmp;
    //tmp.run();
    //return tmp.getResults();
    QVector<QVector<QVector<float> > > m;
    return m;
}
