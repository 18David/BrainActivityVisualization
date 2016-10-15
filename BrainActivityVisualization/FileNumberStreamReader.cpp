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
void FileNumberStreamReader::FileTextStreamReader(const float& filepath) {

}

/**
 * Destructeur qui détruit les éléments en mémoire tel que le QFile et le QTextStream
 */
void FileNumberStreamReader::~FileTextStreamReader() {

}

/**
 * Ouvre le fichier en lecture.
 * @return bool
 */
bool FileNumberStreamReader::open() {
    return false;
}

/**
 * Ferme le fichier si il a été ouvert correctement.
 * @return void
 */
void FileNumberStreamReader::close() {
    return;
}

/**
 * Lit le prochain mot et rempli la wariable "word" avec le mot lu. Si on est à la fin du fichier et qu'aucun mot n'est présent la variable "word" sera vide.
 * 
 * Renvoie true si la variable word n'est pas vide.
 * @param number
 * @return bool
 */
bool FileNumberStreamReader::readNumber(float& number) {
    return false;
}

/**
 * Renvoie true si on est à la fin du fichier ou si le fichier n'est pas ouvert.
 * @return bool
 */
bool FileNumberStreamReader::atEnd() {
    return false;
}