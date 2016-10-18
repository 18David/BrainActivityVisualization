/**
 * Project Untitled
 */


#ifndef _FILENUMBERSTREAMREADER_H
#define _FILENUMBERSTREAMREADER_H

#include "AbstractFileReader.h"
#include "AbstractMatrixReader.h"

#include <QFile>
#include <QTextStream>


class FileNumberStreamReader: public AbstractMatrixReader {
public: 
    
    /**
     * Constructeur prenant en paramètre le chemin du fichier à lire
     * @param filepath
     */
    FileNumberStreamReader(const QString& filepath);
    
    /**
     * Destructeur qui détruit les éléments en mémoire tel que le QFile et le QTextStream
     */
    ~FileNumberStreamReader();
    
    /**
     * Ouvre le fichier en lecture.
     */
    bool open();
    
    /**
     * Ferme le fichier si il a été ouvert correctement.
     */
    void close();
    
    /**
     * Lit le prochain mot et rempli la wariable "word" avec le mot lu. Si on est à la fin du fichier et qu'aucun mot n'est présent la variable "word" sera vide.
     * 
     * Renvoie true si la variable word n'est pas vide.
     * @param number
     */
    bool readNumber(float& number);    
    
    /**
     * Renvoie true si on est à la fin du fichier ou si le fichier n'est pas ouvert.
     */
    bool atEnd();
private: 
    /**
     * Attribut du type pointeur sur QTextStream
     * 
     * La classe QTextStream permet de lire le texte d'un fichier. Il faut lui donner un pointeur sur QFile dans son constructeur pour qu'elle lise le fichier.
     * 
     *  Attention le fichier doit tout d'abord être ouvert en lecture avant de le donner à QTextStream !
     */
    QTextStream* m_stream;
    /**
     * Attribut du type pointeur sur QFile
     * 
     * La classe QFile permet d'ouvrir/fermer un fichier.
     */
    QFile* m_file;
};

#endif //_FILENUMBERSTREAMREADER_H
