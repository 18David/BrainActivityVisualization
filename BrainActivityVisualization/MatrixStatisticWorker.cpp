/**
 * Project Untitled
 */


#include "MatrixStatisticWorker.h"

/**
 * MatrixStatisticWorker implementation
 * 
 * Classe permettant de calculer le nombre d'occurrence pour chaque mot d'un fichier et de donner son résultat sous forme de dictionnaire.
 */




/**
 * Définir quel lecteur de mot utiliser
 * @param reader
 * @return void
 */
MatrixStatisticWorker::MatrixStatisticWorker()
{

}

MatrixStatisticWorker::~MatrixStatisticWorker()
{

}

void MatrixStatisticWorker::setReader(AbstractMatrixReader *reader) {
    m_reader = reader;
}

/**
 * Retourne simplement la matrix
 * @return const float*
 */
const QVector<QVector<QVector<float>>> MatrixStatisticWorker::getResults() const{
    return m_matrix;
}

/**
 * Réalise le traitement :
 * 
 * demande au lecteur de mot les mots un par un et ajoute à la matrix le float
 * @return void
 */
void MatrixStatisticWorker::compute() {
    float nb;
    bool ok = false;
    if(m_reader->open()) {
        ok= true;
        for(int i=0;i<20;i++){
            for(int j=0;j<20;j++){
                for(int k=0;k<5;k++){
                    m_reader->readNumber(nb);
                    m_matrix[i][j][k]=nb;
                }
            }
        }
        m_reader->close();
    } ;
}
