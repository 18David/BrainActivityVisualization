/**
 * Project Untitled
 */

#include "filenumberstreamreader.h"
#include "gmainwindow.h"
#include "ui_gmainwindow.h"
#include <QFileDialog>
#include <QMessageBox>
#include <QTableWidget>
#include <QPoint>

GMainWindow::GMainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::GMainWindow)
{
    ui->setupUi(this);
    ui->tableWidget->setRowCount(20);
    ui->tableWidget->setColumnCount(20);

    m_coherenceManager.setRange(0.5,2.0);   // VALEUR PAR DEFAUT A MODIFIER !!!!!!
    ui->lineEditMiniRange->setText("0.5");  // min
    ui->lineEditMaxRange->setText("2.0");   // max
    connect(&m_matrixManager,SIGNAL(computeFinishedTotally()),this,SLOT(computeFinished()));
    connect(ui->actionOpen,SIGNAL(triggered(bool)),this,SLOT(openFile()));
    connect(&m_matrixManager, SIGNAL(progressChanged(int)), ui->progressBar, SLOT(setValue(int)));
    connect(&m_matrixManager, SIGNAL(progressRangeChanged(int,int)), ui->progressBar, SLOT(setRange(int,int)));
    connect(ui->pushButtonUp, SIGNAL(releaseMouse()), this, SLOT(setCoherenceRange(float,float)));

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
void GMainWindow::openFile()
    {
        m_fileName = QFileDialog::getOpenFileName(this,tr("Open a file"),"","Matrix file (*.txt)");
        if(m_fileName.isEmpty()){
            QMessageBox::information(this,tr("Fichier Introuvable"),tr("Aucun fichier !"));
        }else{

            //int ret = QMessageBox::question(this, "Multithread", "Utiliser multithread ?", QMessageBox::Yes | QMessageBox::No);
            computeFile(QDir(m_fileName), false/*ret == QMessageBox::Yes*/);

    }

}

/**
 * Récupère les chemins des fichiers présent dans le dossier passé en paramètre.
 * 
 * Pour chaque fichier crée un lecteur de mot et l'ajoute à la liste "m_readers"
 * 
 * Lance le traitement  sur les fichiers du dossier en multithread ou non (suivant la valeur du booléen passé en paramètre) en passant la liste "m_readers" au "m_wordStatisticMatrixManager" et en lancant le calcul à l'aide de sa méthode "run"
 * @param dir
 * @param useMultithread
 * @return void
 */
void GMainWindow::computeFile(QDir dir, bool useMultithread)
{
    QList<AbstractMatrixReader *> readers;
    QList<QFileInfo> files = dir.entryInfoList(QStringList() << "*.txt", QDir::Files);
    for(int i=0;i<files.size();i++){
        readers.append(new FileNumberStreamReader(files.at(i).absoluteFilePath()));

       m_matrixManager.setReaders(readers);
       m_matrixManager.setUseMultithread(useMultithread);
       m_matrixManager.run();
       m_coherenceManager.setMatrix(m_matrixManager.getResults());
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
   // int points[20][2]={{0,0},{0,0},{0,0},{0,0},{0,0},{0,0},{0,0},{0,0},{0,0},{0,0},{0,0},{0,0},{0,0},{0,0},{0,0},{0,0},{0,0},{0,0},{0,0},{0,0}};
    QList<QPoint *> res;
    res= m_coherenceManager.getResults();
    //traitement pour afficher
    foreach(QPoint * line,res){
        /* draw line
         * line[0] point de depart
         * line[1] point d'arrivee
        */
    }


}

void GMainWindow::setCoherenceRange(float min, float max)
{
    m_coherenceManager.setRange(min,max);
    computeFile(QDir(m_fileName),false);

}
