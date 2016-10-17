/**
 * Project Untitled
 */

#include "abstractmatrixreader.h"
#include "filenumberstreamreader.h"
#include "gmainwindow.h"
#include "ui_gmainwindow.h"
#include <QFileDialog>
#include <QMessageBox>

#include "GMainWindow.h"


GMainWindow::GMainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::GMainWindow)
{
    ui->setupUi(this);

    ui->customPlot->xAxis->setAutoTicks(false);
    ui->customPlot->xAxis->setAutoTickLabels(false);

    ui->customPlot->setInteractions(QCP::iRangeDrag | QCP::iRangeZoom);

    connect(&m_matrixManager,SIGNAL(computeFinishedTotally()),this,SLOT(computeFinished()));
    connect(ui->actionOpen,SIGNAL(triggered(bool)),this,SLOT(openDirectory()));
}

GMainWindow::~GMainWindow()
{
    delete ui;
}
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
void GMainWindow::openDirectory()
    {
        QString fileName = QFileDialog::getExistingDirectory(this,tr("Ouvrir"), "C:\\Users\\18gon\\OneDrive\\Documents\\OccurrenceDesMots");
        if(fileName.isEmpty()){
            QMessageBox::information(this,tr("Dossier Introuvable"),tr("Aucun dossier !"));
        }else{
            int ret = QMessageBox::question(this, "Multithread", "Utiliser multithread ?", QMessageBox::Yes | QMessageBox::No);
            computeDirectory(QDir(fileName), ret == QMessageBox::Yes);

    }

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
void GMainWindow::computeDirectory(QDir dir, bool useMultithread)
{
    QList<AbstractMatrixReader *> readers;
    QList<QFileInfo> files = dir.entryInfoList(QStringList() << "*.cpp", QDir::Files);
    for(int i=0;i<files.size();i++){
        readers.append(new FileTextStreamReader(files.at(i).absoluteFilePath()));

       m_matrixManager.setReaders(readers);
       m_matrixManager.setUseMultithread(useMultithread);
       m_matrixManager.run();
    }
}

/**
 * Connecté au signal "computeFinished" du WordStatisticWorkerManager.
 * 
 * Lorsque ce slot est appelé il va récupérer  les résultats et les afficher dans la fenêtre
 * @return void
 */
void GMainWindow::computeFinished()
{

}
