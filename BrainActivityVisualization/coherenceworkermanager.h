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

    void setStartTime(QList<int> startTime);

    /**
     * Défini si il faut utiliser le mode multithread ou non
     * @param yes
     */
    void setUseMultithread(bool yes);

    /**
     * Retourne les résultats finaux
     */
    const QList<QVector<QVector<QVector<float> > > > getResults();
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
    QList<QVector<QVector<QVector<float>>>> m_matrix;
    QFuture<QList<QVector<QVector<QVector<float>>>>> m_future;
    QFutureWatcher<QList<QVector<QVector<QVector<float>>>>> m_watcher;
    bool m_multithreadActivated;
    QList<int> m_startTime;


    static const QVector<QVector<QVector<float> > > staticRun(int startTime);


private slots:
    void multithreadFinished();
signals:
    void computeFinishedTotally();
};


#endif // COHERENCEWORKERMANAGER_H
