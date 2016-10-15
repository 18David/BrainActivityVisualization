/**
 * Project Untitled
 */


#ifndef _ABSTRACTFILEREADER_H
#define _ABSTRACTFILEREADER_H

#include "AbstractMatrixReader.h"


class AbstractFileReader: public AbstractMatrixReader {
public: 
    
    void AbstractFileReader();
    
    void ~AbstractFileReader();
    
    /**
     * @param source
     */
    bool setSource(FileSource* source);
    
    QFile* file();
    
    bool open();
    
    void close();
    
    AbstractSource* getSource();
private: 
    QFile* m_file;
};

#endif //_ABSTRACTFILEREADER_H