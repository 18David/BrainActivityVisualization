/**
 * Project Untitled
 */


#ifndef _GMAINWINDOW_H
#define _GMAINWINDOW_H

#include "QMainWindow.h"
#include "AbstractMatrixReader.h"
#include "MatrixStatisticWorkerManager.h"
#include "MatrixStatisticWorkerManager.h"


class GMainWindow: public QMainWindow {
public: 
    
    /**
     * Affiche une fenêtre de dialogue permettant de choisir le répertoire des fichiers à lire
     * 
     * Connecté à l'action "Ouvrir" dans le menu
     */
    void openDirectory();
    
    /**
     * Récupère les chemins des fichiers présent dans le dossier passé en paramètre.
     * 
     * Pour chaque fichier crée un lecteur de mot et l'ajoute à la liste "m_readers"
     * 
     * Lance le traitement  sur les fichiers du dossier en multithread ou non (suivant la valeur du booléen passé en paramètre) en passant la liste "m_readers" au "m_wordStatisticWorkerManager" et en lancant le calcul à l'aide de sa méthode "run"
     * @param dir
     * @param useMultithread
     */
    void computeDirectory(QDir dir, bool useMultithread);
private: 
    /**
     * QList contenant des pointeurs sur AbstractWordReader
     */
    Vector<AbstractMatrixReader> m_readers;
    MatrixStatisticWorkerManager m_wordStatisticWorkerManager;
    /**
     * Attribut du type WordStatisticWorkerManager
     */
    MatrixStatisticWorkerManager m_matrixStatisticWorkerManager;
    
    /**
     * Connecté au signal "computeFinished" du WordStatisticWorkerManager.
     * 
     * Lorsque ce slot est appelé il va récupérer  les résultats et les afficher dans la fenêtre
     */
    void computeFinished();
};

#endif //_GMAINWINDOW_H