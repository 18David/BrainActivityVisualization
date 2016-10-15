/**
 * Project Untitled
 */


#ifndef _MATRIXSTATISTICWORKER_H
#define _MATRIXSTATISTICWORKER_H

#include "AbstractWorker.h"
#include "AbstractMatrixReader.h"


class MatrixStatisticWorker: public AbstractWorker {
public: 
    
    void MatrixStatisticWorker();
    
    /**
     * Définir quel lecteur de mot utiliser
     * @param reader
     */
    void setReader(AbstractMatrixReader* reader);
    
    /**
     * Retourne simplement le dictionnaire
     */
    const QList<float*>& getResults();
protected: 
    
    /**
     * Réalise le traitement :
     * 
     * demande au lecteur de mot les mots un par un et ajoute au dictionnaire le nombre d'occurence pour chaque mot
     */
    void compute();
private: 
    /**
     * Dictionnaire avec comme clé une chaine de caractère (le mot) et en valeur un entier (le nombre d'occurence du mot)
     */
    Qlist<float*> m_EegRecord;
    /**
     * Attribut du type pointeur sur AbstractWordReader
     */
    AbstractMatrixReader m_reader;
};

#endif //_MATRIXSTATISTICWORKER_H