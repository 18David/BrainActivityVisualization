/**
 * Project Untitled
 */


#ifndef _MATRIXSTATISTICWORKERMANAGER_H
#define _MATRIXSTATISTICWORKERMANAGER_H

#include "AbstractWorker.h"
#include "AbstractMatrixReader.h"


class MatrixStatisticWorkerManager: public AbstractWorker {
public: 
    
    void MatrixStatisticWorkerManager();
    
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
    const Qlist<float*>& getResults();
protected: 
    
    void MatrixStatisticWorkerManager();
    
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
    Qlist<float*> m_EegRecord;
    QFuture<Qlist<float*>> m_future;
    QFutureWatcher<Qlist<float*>> m_watcher;
    bool m_multithreadActivated;
    /**
     * QList contenant des pointeurs sur AbstractWordReader
     */
    Vector<AbstractMatrixReader> m_readers;
    
    /**
     * Assemble la liste des résultats dans le dictionnaire de cette classe (m_statisticMap)
     * @param results
     */
    void assembleResults(const QList< Qlist<float*>> & results);
    
    /**
     * Crée un WordStatisticWorker, lui donne le lecteur de mot à utiliser et lance son traitement à l'aide la méthode "run"
     * 
     * Retourne le résultat du worker
     * @param reader
     */
    static Qlist<float*> staticRun(AbstractMatrixReader* reader);
    
    void multithreadFinished();
};

#endif //_MATRIXSTATISTICWORKERMANAGER_H