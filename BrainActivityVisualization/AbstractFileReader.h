/**
 * Project Untitled
 */


#ifndef _ABSTRACTFILEREADER_H
#define _ABSTRACTFILEREADER_H

#include "AbstractMatrixReader.h"
#include <QFile>

class AbstractFileReader: public AbstractMatrixReader {
public: 
    
    AbstractFileReader();
    
    ~AbstractFileReader();
    
    /**
     * @param source
     */
    bool setSource(QFile* source);
    
    QFile* file();
    
    bool open();
    
    void close();
    
    QFile* getSource();
private: 
    QFile* m_file;
};

#endif //_ABSTRACTFILEREADER_H
