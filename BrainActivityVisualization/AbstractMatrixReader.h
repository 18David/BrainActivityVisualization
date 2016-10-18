/**
 * Project Untitled
 */

#include <QString>


#ifndef _ABSTRACTMATRIXREADER_H
#define _ABSTRACTMATRIXREADER_H

//#include "ErrorInformer.h"


class AbstractMatrixReader {
public: 
    AbstractMatrixReader();
    virtual ~AbstractMatrixReader();
    /**
     * méthode virtuelle pure
     * @param word
     */
    virtual bool readNumber(float& number) = 0;
    
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

};

#endif //_ABSTRACTMATRIXREADER_H
