/**
 * Project Untitled
 */


#include "AbstractWorker.h"

/**
 * AbstractWorker implementation
 * 
 * Classe abstraite représentant un "Worker"
 * 
 * Un "Worker" est un objet qui fait un calcul quelconque et envoie sa progression
 * 
 * Le calcul est réaliser dans la méthode "compute"
 */


virtual void AbstractWorker::~AbstractWorker() {

}

/**
 * Retourne la progression courante
 * @return int
 */
int AbstractWorker::getProgress() {
    return 0;
}

/**
 * Met la progression courante à 0
 * 
 * Lance le calcul à l'aide de la méthode "compute"
 * 
 * Met la progression à 100
 * 
 * Emet le signal "finished"
 * @return void
 */
void AbstractWorker::run() {
    return;
}

/**
 * @param progress
 * @return void
 */
void AbstractWorker::progressChanged(int progress) {
    return;
}

/**
 * @param min
 * @param max
 * @return void
 */
void AbstractWorker::progressRangeChanged(int min, int max) {
    return;
}

/**
 * @return void
 */
void AbstractWorker::finished() {
    return;
}

/**
 * Méthode virtuelle pure
 * @return void
 */
virtual void AbstractWorker::compute() {
    return;
}

/**
 * Modifie la progression courante et emet le signal "progressChanged" si la progression a changée
 * @param progress
 * @return void
 */
void AbstractWorker::setProgress(int progress) {
    return;
}

/**
 * Modifie les attributs min et max et emet le signal "progressRangeChanged" si le min ou le max a changé
 * @param min
 * @param max
 * @return void
 */
void AbstractWorker::setProgressRange(int min, int max) {
    return;
}