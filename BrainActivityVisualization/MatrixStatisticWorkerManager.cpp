/**
 * Project Untitled
 */


#include "FileNumberStreamReader.h"
#include "MatrixStatisticWorker.h"
#include "MatrixStatisticWorkerManager.h"
#include <QtConcurrent/QtConcurrent>

/**
 * MatrixStatisticWorkerManager implementation
 * 
 * Classe permettant de réaliser le calcul sur une liste de lecteurs de mots
 */


MatrixStatisticWorkerManager::MatrixStatisticWorkerManager() {

}

MatrixStatisticWorkerManager::~MatrixStatisticWorkerManager()
{

}

/**
 * Défini si il faut utiliser le mode multithread ou non
 * @param yes
 * @return void
 */
void MatrixStatisticWorkerManager::setUseMultithread(bool yes) {
    m_multithreadActivated=yes;
}

void MatrixStatisticWorkerManager::setReaders(QList<AbstractMatrixReader *> readers)
{
   m_readers.append(readers);
}

/**
 * Définit la liste de lecteur de mots à utiliser dans la méthode "compute"
 * @param readers
 * @return void
 */
/*void MatrixStatisticWorkerManager::setReaders(QList<AbstractMatrixReader*> readers) {
    m_readers= readers;
}*/

/**
 * Retourne les résultats finaux
 * @return const Qlist<float*>&
 */
const QList<QVector<QVector<QVector<float>>>> MatrixStatisticWorkerManager::getResults() {
    return m_matrix;
}


/**
 * Si le mode multithread n'est pas activé, parcours la liste des lecteurs de mot et les passe un par un à la méthode "staticRun".
 * 
 * Récupère les résultats de la méthode staticRun et les stock dans une QList temporaire.
 * 
 * Appel la méthode "assembleResults" en lui donnant la liste des résultats
 * 
 * Emet le signal finished
 * @return void
 */
void MatrixStatisticWorkerManager::compute()
{

    if(!m_multithreadActivated)
    {

        setProgressRange(0, m_readers.size());

        for(int i=0;i<m_readers.size();i++)
        {
            m_matrix.append(staticRun(m_readers.at(i)));
        }
        emit computeFinishedTotally();

    }

    else
    {
        m_future = QtConcurrent::mapped(m_readers, &staticRun);
        m_watcher.setFuture(m_future);
    }

}


/**
 * Assemble la liste des résultats dans le dictionnaire de cette classe (m_statisticMap)
 * @param results
 * @return void
 */
/*void MatrixStatisticWorkerManager::assembleResults(const QList<float *> &results)
{
    results=m_matrix;
}*/


/**
 * Crée un WordStatisticWorker, lui donne le lecteur de mot à utiliser et lance son traitement à l'aide la méthode "run"
 * 
 * Retourne le résultat du worker
 * @param reader
 * @return float*
 */
QVector<QVector<QVector<float>>> MatrixStatisticWorkerManager::staticRun(AbstractMatrixReader* reader) {
    MatrixStatisticWorker tmp;
    tmp.setReader(reader);
    tmp.run();
    return tmp.getResults();
}

/**
 * @return void
 */
void MatrixStatisticWorkerManager::multithreadFinished()
{
   m_matrix=m_future.results();
   emit computeFinishedTotally();
}
