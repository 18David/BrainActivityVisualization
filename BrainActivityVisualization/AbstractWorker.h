/**
 * Project Untitled
 */


#ifndef _ABSTRACTWORKER_H
#define _ABSTRACTWORKER_H

#include "QObject.h"


class AbstractWorker: public QObject {
public: 
    AbstractWorker();
    virtual void ~AbstractWorker() = 0;
    
    /**
     * Retourne la progression courante
     */
    int getProgress();
public slots:
    /**
     * Met la progression courante à 0
     * 
     * Lance le calcul à l'aide de la méthode "compute"
     * 
     * Met la progression à 100
     * 
     * Emet le signal "finished"
     */
    void run();
signals:
    /**
     * @param progress
     */
    void progressChanged(int progress);
    
    /**
     * @param min
     * @param max
     */
    void progressRangeChanged(int min, int max);
    
    void finished();
protected: 
    
    /**
     * Méthode virtuelle pure
     */
    virtual void compute() = 0;
protected slots:
    /**
     * Modifie la progression courante et emet le signal "progressChanged" si la progression a changée
     * @param progress
     */
    void setProgress(int progress);
    
    /**
     * Modifie les attributs min et max et emet le signal "progressRangeChanged" si le min ou le max a changé
     * @param min
     * @param max
     */
    void setProgressRange(int min, int max);
private: 
    /**
     * Attribut qui stocke la progression courante
     */
    int m_progress;
    /**
     * Attribut qui stocke la valeur minimum que la progression peut avoir.
     * 
     * Par exemple si la progression est entre 0 et 500 cet attribut aura comme valeur 0
     */
    int m_minProgress;
    /**
     * Attribut qui stocke la valeur maximum que la progression peut avoir.
     * 
     * Par exemple si la progression est entre 0 et 500 cet attribut aura comme valeur 500
     */
    int m_maxProgress;
};

#endif //_ABSTRACTWORKER_H
