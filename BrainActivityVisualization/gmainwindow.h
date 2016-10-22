/**
 * Project Untitled
 */


#ifndef _GMAINWINDOW_H
#define _GMAINWINDOW_H
#include <QDir>
#include <QMainWindow>
#include "AbstractMatrixReader.h"
#include "MatrixStatisticWorkerManager.h"
#include "coherenceworkermanager.h"

namespace Ui {
class GMainWindow;
}

class GMainWindow : public QMainWindow
{
    Q_OBJECT

public: 
    explicit GMainWindow(QWidget *parent = 0);
    ~GMainWindow();
    /**
     * Récupère les chemins des fichiers présent dans le dossier passé en paramètre.
     * 
     * Pour chaque fichier crée un lecteur de mot et l'ajoute à la liste "m_readers"
     * 
     * Lance le traitement  sur les fichiers du dossier en multithread ou non (suivant la valeur du booléen passé en paramètre) en passant la liste "m_readers" au "m_wordStatisticWorkerManager" et en lancant le calcul à l'aide de sa méthode "run"
     * @param dir
     * @param useMultithread
     */
    void computeFile(QDir dir, bool useMultithread);
public slots:
    /**
     * Affiche une fenêtre de dialogue permettant de choisir le répertoire des fichiers à lire
     *
     * Connecté à l'action "Ouvrir" dans le menu
     */
    void openFile();
private: 

    Ui::GMainWindow *ui;
    MatrixStatisticWorkerManager m_matrixManager;
    float minRange;
    CoherenceWorkerManager m_coherenceManager;



protected:
    void paintEvent(QPaintEvent *evt);


private slots:
    /**
     * Connecté au signal "computeFinished" du WordStatisticWorkerManager.
     * 
     * Lorsque ce slot est appelé il va récupérer  les résultats et les afficher dans la fenêtre
     */
    void computeFinished();
};

#endif //_GMAINWINDOW_H
