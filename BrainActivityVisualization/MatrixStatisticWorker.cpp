/**
 * Project Untitled
 */


#include "MatrixStatisticWorker.h"

/**
 * MatrixStatisticWorker implementation
 * 
 * Classe permettant de calculer le nombre d'occurrence pour chaque mot d'un fichier et de donner son résultat sous forme de dictionnaire.
 */


void MatrixStatisticWorker::MatrixStatisticWorker() {

}

/**
 * Définir quel lecteur de mot utiliser
 * @param reader
 * @return void
 */
void MatrixStatisticWorker::setReader(AbstractMatrixReader* reader) {
    return;
}

/**
 * Retourne simplement le dictionnaire
 * @return const QList<float*>&
 */
const QList<float*>& MatrixStatisticWorker::getResults() {
    return null;
}

/**
 * Réalise le traitement :
 * 
 * demande au lecteur de mot les mots un par un et ajoute au dictionnaire le nombre d'occurence pour chaque mot
 * @return void
 */
void MatrixStatisticWorker::compute() {
    return;
}