/**
 * Project Untitled
 */


#include "AbstractFileReader.h"

/**
 * AbstractFileReader implementation
 */


void AbstractFileReader::AbstractFileReader() {

}

void AbstractFileReader::~AbstractFileReader() {

}

/**
 * @param source
 * @return bool
 */
bool AbstractFileReader::setSource(FileSource* source) {
    return false;
}

/**
 * @return QFile*
 */
QFile* AbstractFileReader::file() {
    return null;
}

/**
 * @return bool
 */
bool AbstractFileReader::open() {
    return false;
}

/**
 * @return void
 */
void AbstractFileReader::close() {
    return;
}

/**
 * @return AbstractSource*
 */
AbstractSource* AbstractFileReader::getSource() {
    return null;
}