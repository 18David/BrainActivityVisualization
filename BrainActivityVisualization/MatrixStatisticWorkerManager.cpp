/**
 * Project Untitled
 */


#include "MatrixStatisticWorkerManager.h"

/**
 * MatrixStatisticWorkerManager implementation
 * 
 * Classe permettant de réaliser le calcul sur une liste de lecteurs de mots
 */


void MatrixStatisticWorkerManager::MatrixStatisticWorkerManager() {

}

/**
 * Défini si il faut utiliser le mode multithread ou non
 * @param yes
 * @return void
 */
void MatrixStatisticWorkerManager::setUseMultithread(bool yes) {
    return;
}

/**
 * Définit la liste de lecteur de mots à utiliser dans la méthode "compute"
 * @param readers
 * @return void
 */
void MatrixStatisticWorkerManager::setReaders(QList<AbstractMatrixReader*> readers) {
    return;
}

/**
 * Retourne les résultats finaux
 * @return const Qlist<float*>&
 */
const Qlist<float*>& MatrixStatisticWorkerManager::getResults() {
    return null;
}

void MatrixStatisticWorkerManager::MatrixStatisticWorkerManager() {

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
void MatrixStatisticWorkerManager::compute() {
    return;
}

/**
 * Assemble la liste des résultats dans le dictionnaire de cette classe (m_statisticMap)
 * @param results
 * @return void
 */
void MatrixStatisticWorkerManager::assembleResults(const QList< Qlist<float*>> & results) {
    return;
}

/**
 * Crée un WordStatisticWorker, lui donne le lecteur de mot à utiliser et lance son traitement à l'aide la méthode "run"
 * 
 * Retourne le résultat du worker
 * @param reader
 * @return Qlist<float*>
 */
static Qlist<float*> MatrixStatisticWorkerManager::staticRun(AbstractMatrixReader* reader) {
    return null;
}

/**
 * @return void
 */
void MatrixStatisticWorkerManager::multithreadFinished() {
    return;
}