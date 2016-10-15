/**
 * Project Untitled
 */


#include "GMainWindow.h"

/**
 * GMainWindow implementation
 * 
 * Fenêtre principale contenant le graphique et le menu permettant d'ouvrir un dossier
 */


/**
 * Affiche une fenêtre de dialogue permettant de choisir le répertoire des fichiers à lire
 * 
 * Connecté à l'action "Ouvrir" dans le menu
 * @return void
 */
void GMainWindow::openDirectory() {
    return;
}

/**
 * Récupère les chemins des fichiers présent dans le dossier passé en paramètre.
 * 
 * Pour chaque fichier crée un lecteur de mot et l'ajoute à la liste "m_readers"
 * 
 * Lance le traitement  sur les fichiers du dossier en multithread ou non (suivant la valeur du booléen passé en paramètre) en passant la liste "m_readers" au "m_wordStatisticWorkerManager" et en lancant le calcul à l'aide de sa méthode "run"
 * @param dir
 * @param useMultithread
 * @return void
 */
void GMainWindow::computeDirectory(QDir dir, bool useMultithread) {
    return;
}

/**
 * Connecté au signal "computeFinished" du WordStatisticWorkerManager.
 * 
 * Lorsque ce slot est appelé il va récupérer  les résultats et les afficher dans la fenêtre
 * @return void
 */
void GMainWindow::computeFinished() {
    return;
}