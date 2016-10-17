/**
 * Project Untitled
 */


#ifndef _ABSTRACTMATRIXREADER_H
#define _ABSTRACTMATRIXREADER_H

#include "ErrorInformer.h"


class AbstractMatrixReader {
public: 
    
    /**
     * méthode virtuelle pure
     * @param word
     */
    virtual bool readNumber(QString& word) = 0;
    
    /**
     * méthode virtuelle pure
     */
    virtual bool atEnd() = 0;
    
    /**
     * méthode virtuelle pure
     */
    virtual bool open() = 0;
    
    /**
     * méthode virtuelle pure
     */
    virtual void close() = 0;
protected: 
    
    /**
     * destructeur
     */
    virtual void AbstractMatrixReader() = 0;
};

#endif //_ABSTRACTMATRIXREADER_H
