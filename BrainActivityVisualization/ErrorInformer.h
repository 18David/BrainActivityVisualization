/**
 * Project Untitled
 */


#ifndef _ERRORINFORMER_H
#define _ERRORINFORMER_H

class ErrorInformer {
public: 
    
    QString error();
    
    bool hasError();
    
    void resetError();
protected: 
    
    /**
     * @param error
     */
    void setError(QString error);
private: 
    QString error;
};

#endif //_ERRORINFORMER_H