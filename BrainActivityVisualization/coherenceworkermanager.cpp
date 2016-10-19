#include "coherenceworkermanager.h"
#include "coherenceworker.h"

CoherenceWorkerManager::CoherenceWorkerManager()
{

}

CoherenceWorkerManager::~CoherenceWorkerManager()
{

}

void CoherenceWorkerManager::setStartTime(QList<int> startTime)
{
    m_startTime=startTime;
}

const QList<QVector<QVector<QVector<float> > > > CoherenceWorkerManager::getResults()
{
    return m_matrix;
}

void CoherenceWorkerManager::compute()
{
    foreach (int i, m_startTime) {
         m_matrix.append(staticRun(i));
    }

}

const QVector<QVector<QVector<float> > > CoherenceWorkerManager::staticRun(int startTime)
{
    CoherenceWorker tmp;
    //tmp.run(startTime);
    //return tmp.getResults();
    QVector<QVector<QVector<float> > > m;
    return m;
}
