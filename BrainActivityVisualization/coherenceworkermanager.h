#ifndef COHERENCEWORKERMANAGER_H
#define COHERENCEWORKERMANAGER_H

#include "AbstractWorker.h"
#include <QList>
#include <QFuture>
#include <QFutureWatcher>

class CoherenceWorkerManager: public AbstractWorker {
    Q_OBJECT
public:

    CoherenceWorkerManager();
    ~CoherenceWorkerManager();

    void setMatrix(QVector<QVector<QVector<float>>> matrix);
    void setRange(float min,float max);

    /**
     * Défini si il faut utiliser le mode multithread ou non
     * @param yes
     */
   // void setUseMultithread(bool yes);

    /**
     * Retourne les résultats finaux
     */
    const QList<QPoint *> getResults();
protected:
    /**
     * Si le mode multithread n'est pas activé, parcours la liste des lecteurs de mot et les passe un par un à la méthode "staticRun".
     *
     * Récupère les résultats de la méthode staticRun et les stock dans une QList temporaire.
     *
     * Appel la méthode "assembleResults" en lui donnant la liste des résultats
     *
     * Emet le signal finished
     */
    void compute();
private:
    QVector<QVector<QVector<float>>> m_matrix;
    //QFuture<QList<QVector<QVector<QVector<float>>>>> m_future;
    //QFutureWatcher<QList<QVector<QVector<QVector<float>>>>> m_watcher;
   // bool m_multithreadActivated;
    QList<QPoint *> m_points;
    float m_minRange;
    float m_maxRange;

    static QList<QPoint *> staticRun();
    bool inRange(float nb);

private slots:
  //  void coherenceMultithreadFinished();
signals:
   // void coherenceComputeFinishedTotally();
};


#endif // COHERENCEWORKERMANAGER_H
