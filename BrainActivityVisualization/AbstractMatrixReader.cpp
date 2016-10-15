/**
 * Project Untitled
 */


#include "AbstractMatrixReader.h"

/**
 * AbstractMatrixReader implementation
 * 
 * Classe abstraite permettant de lire mot par mot dans une source quelconque (fichier, base de donnée, site web, etc...)
 */


/**
 * méthode virtuelle pure
 * @param word
 * @return bool
 */
virtual bool AbstractMatrixReader::readNumber(QString& word) {
    return false;
}

/**
 * méthode virtuelle pure
 * @return bool
 */
virtual bool AbstractMatrixReader::atEnd() {
    return false;
}

/**
 * méthode virtuelle pure
 * @return bool
 */
virtual bool AbstractMatrixReader::open() {
    return false;
}

/**
 * méthode virtuelle pure
 * @return void
 */
virtual void AbstractMatrixReader::close() {
    return;
}

/**
 * destructeur
 */
virtual void AbstractMatrixReader::AbstractMatrixReader() {

}