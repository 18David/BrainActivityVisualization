#include "coherenceworkermanager.h"
#include "coherenceworker.h"

#include <QPoint>

CoherenceWorkerManager::CoherenceWorkerManager()
{

}

CoherenceWorkerManager::~CoherenceWorkerManager()
{

}

void CoherenceWorkerManager::setMatrix(QVector<QVector<QVector<float>>> matrix)
{
    m_matrix=matrix;
}

void CoherenceWorkerManager::setRange(float min, float max)
{
    m_minRange=min;
    m_maxRange=max;
}

const QVector<QList<QVector<QPoint>>> CoherenceWorkerManager::getResults()
{
    return m_points;
}

void CoherenceWorkerManager::raz()
{
  //  m_points.clear();
}

void CoherenceWorkerManager::compute()
{
    QVector<int> cpt;
    QVector<int> old_size;
    for(int i = 0;i<5;i++)
    {
        if(m_points.size()>i){
            old_size.append(m_points[i].size());
        }
        else{
            QList<QVector<QPoint>> init;
            m_points.append(init);
            old_size.append(0);
        }
        cpt.append(0);
    }
    int points[20][2]={{130,343},{339,329},{267,243},{269,328},{200,330},{406,342},{214,405},{323,404},{438,243},{406,144},{354,243},{338,157},{324,81},{268,157},{183,243},{199,157},{213,81},{97,243},{130,144},{269,410}};
    int max_i=1;
    for (int j=1;j<20;j++){ //pacours de la partie superieur de la matrix par rapport a la mediane
        for (int i=0;i<max_i;i++) {
            for(int k=0; k<5;k++){
                if(inRange(m_matrix[i][j][k])){

                    QVector<QPoint> tmp;
                    if(tmp.size()!=0){
                        tmp.erase(0);
                    }
                    tmp.append(QPoint(points[i][0],points[i][1]));
                    tmp.append(QPoint(points[j][0],points[j][1]));
                    if(m_points[k].size()>cpt[k])
                    {
                        m_points[k][cpt[k]]=tmp;
                    }
                    else{
                        m_points[k].append(tmp);
                    }
                    cpt[k]++;
                }
            }
        }
        max_i++;
    }
    for(int k=0; k<5;k++){
        for(int i =cpt[k]; i<old_size[k];i++)
        {
            m_points[k].removeLast();
        }
    }
    emit computeFinishedTotally();
}

/*QList<QPoint *> CoherenceWorkerManager::staticRun()
{

}*/

bool CoherenceWorkerManager::inRange(float nb)
{
    if(nb>m_minRange&&nb<m_maxRange){
        return true;
    }
    return false;
}

/*void CoherenceWorkerManager::coherenceMultithreadFinished()
{

}*/
