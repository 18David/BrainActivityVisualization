/**
 * Project Untitled
 */


#ifndef _MATRIXSTATISTICWORKER_H
#define _MATRIXSTATISTICWORKER_H

#include "AbstractWorker.h"
#include "AbstractMatrixReader.h"
#include "FileNumberStreamReader.h"
#include <QVector>



class MatrixStatisticWorker: public AbstractWorker {
public: 
    MatrixStatisticWorker();
    ~MatrixStatisticWorker();
    
    /**
     * Définir quel lecteur de mot utiliser
     * @param reader
     */
    void setReader(AbstractMatrixReader* reader);
    
    /**
     * Retourne simplement le dictionnaire
     */
    const QVector<QVector<QVector<float>>> getResults() const;
protected: 
    
    /**
     * Réalise le traitement :
     * 
     * demande au lecteur de mot les mots un par un et ajoute au dictionnaire le nombre d'occurence pour chaque mot
     */
    void compute();
private: 

    QVector<QVector<QVector<float>>> m_matrix;
    /**
     * Attribut du type pointeur sur AbstractWordReader
     */
    AbstractMatrixReader* m_reader;
};

#endif //_MATRIXSTATISTICWORKER_H
