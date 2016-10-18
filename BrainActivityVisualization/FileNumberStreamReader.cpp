/**
 * Project Untitled
 */


#include "FileNumberStreamReader.h"

/**
 * FileNumberStreamReader implementation
 * 
 * Classe qui permet de lire mot par mot un fichier.
 * 
 * Ell hérite de la classe AbstractWordReader
 */


/**
 * Constructeur prenant en paramètre le chemin du fichier à lire
 * @param filepath
 */
FileNumberStreamReader::FileNumberStreamReader(const QString& filepath) {
    m_file = new QFile(filepath);
}

/**
 * Destructeur qui détruit les éléments en mémoire tel que le QFile et le QTextStream
 */
FileNumberStreamReader::~FileNumberStreamReader() {
    delete m_file;
    delete m_stream;
}

/**
 * Ouvre le fichier en lecture.
 * @return bool
 */
bool FileNumberStreamReader::open() {
    bool tmp = m_file->open(QIODevice::ReadOnly);
    if(tmp)
        m_stream = new QTextStream(m_file);
    return tmp;
}

/**
 * Ferme le fichier si il a été ouvert correctement.
 * @return void
 */
void FileNumberStreamReader::close() {
    m_file->close();
}

/**
 * Lit le prochain mot et rempli la wariable "word" avec le mot lu. Si on est à la fin du fichier et qu'aucun mot n'est présent la variable "word" sera vide.
 * 
 * Renvoie true si la variable word n'est pas vide.
 * @param number
 * @return bool
 */
bool FileNumberStreamReader::readNumber(float& number) {
    QString number_str = "";
    bool ok=false;
    QString str="";
    while(!ok && !atEnd()){
        str="";
        str=m_stream->read(1);
        if(!(number_str==""&&str=="")){
            if(str==","||str=="\n"){
                ok=true;
            }else{
                number_str+=str;
            }
        }
    }
    number = number_str.toFloat();
    return ok;
}

/**
 * Renvoie true si on est à la fin du fichier ou si le fichier n'est pas ouvert.
 * @return bool
 */
bool FileNumberStreamReader::atEnd() {
    return m_stream->atEnd();
}
