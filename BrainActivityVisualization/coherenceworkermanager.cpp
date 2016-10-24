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

const QList<QPoint *> CoherenceWorkerManager::getResults()
{
    return m_points;
}

void CoherenceWorkerManager::compute()
{

    int points[20][2]={{1,1},{2,2},{3,3},{4,4},{5,5},{6,6},{7,7},{8,8},{9,9},{10,10},{11,11},{12,12},{13,13},{14,14},{16,16},{17,17},{18,18},{19,19},{20,20},{21,21}};
    int max_i=1;
    for (int j=1;j<20;j++){ //pacours de la partie superieur de la matrix par rapport a la mediane
        for (int i=0;i<max_i;i++) {
            for(int k=0; k<5;k++){
                if(inRange(m_matrix[i][j][k])){
                    QPoint tmp[2];
                    tmp[1].setX(points[i][0]);
                    tmp[1].setY(points[i][1]);
                    tmp[2].setX(points[j][0]);
                    tmp[2].setY(points[j][1]);
                    m_points.append(tmp);
                }
            }
        }
        max_i++;
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
