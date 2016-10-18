/**
 * Project Untitled
 */


#ifndef _MATRIXSTATISTICWORKERMANAGER_H
#define _MATRIXSTATISTICWORKERMANAGER_H

#include "AbstractWorker.h"
#include "AbstractMatrixReader.h"
#include <QList>
#include <QFuture>
#include <QFutureWatcher>


class MatrixStatisticWorkerManager: public AbstractWorker {
public: 
    
    MatrixStatisticWorkerManager();
    ~MatrixStatisticWorkerManager();

    
    /**
     * Défini si il faut utiliser le mode multithread ou non
     * @param yes
     */
    void setUseMultithread(bool yes);
    
    /**
     * Définit la liste de lecteur de mots à utiliser dans la méthode "compute"
     * @param readers
     */
    void setReaders(QList<AbstractMatrixReader*> readers);
    
    /**
     * Retourne les résultats finaux
     */
    const QList<float *> getResults();
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
    QList<float *> m_matrix;
    QFuture<QList<float*>> m_future;
    QFutureWatcher<QList<float*>> m_watcher;
    bool m_multithreadActivated;
    /**
     * QList contenant des pointeurs sur AbstractWordReader
     */
    QList<AbstractMatrixReader *> m_readers;
    
    /**
     * Assemble la liste des résultats dans le dictionnaire de cette classe (m_statisticMap)
     * @param results
     */
    void assembleResults(const QList<float*> & results);
    
    /**
     * Crée un WordStatisticWorker, lui donne le lecteur de mot à utiliser et lance son traitement à l'aide la méthode "run"
     * 
     * Retourne le résultat du worker
     * @param reader
     */
    static QList<float *> staticRun(AbstractMatrixReader* reader);
    
    void multithreadFinished();
};

#endif //_MATRIXSTATISTICWORKERMANAGER_H
