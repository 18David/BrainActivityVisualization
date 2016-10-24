/**
 * Project Untitled
 */

#include "filenumberstreamreader.h"
#include "gmainwindow.h"
#include "ui_gmainwindow.h"
#include <QFileDialog>
#include <QMessageBox>
#include <QTableWidget>
#include <coherencewidget.h>

GMainWindow::GMainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::GMainWindow)
{
    ui->setupUi(this);

    ui->tableWidget->setRowCount(20);
    ui->tableWidget->setColumnCount(20);
    m_coherenceManager.setRange(0,2.0);   // VALEUR PAR DEFAUT A MODIFIER !!!!!!
    ui->lineEditMiniRange->setText("0");  // min
    ui->lineEditMaxRange->setText("2.0");   // max
    //win = new CoherenceWidget(this);

    connect(&m_coherenceManager,SIGNAL(computeFinishedTotally()),this,SLOT(computeFinished()));
    connect(ui->actionOpen,SIGNAL(triggered(bool)),this,SLOT(openFile()));
    connect(&m_matrixManager, SIGNAL(progressChanged(int)), ui->progressBar, SLOT(setValue(int)));
    connect(&m_matrixManager, SIGNAL(progressRangeChanged(int,int)), ui->progressBar, SLOT(setRange(int,int)));
    connect(ui->pushButtonUp, SIGNAL(clicked(bool)), this, SLOT(setCoherenceRange(float,float)));

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
            computeFile();

    }

}

void GMainWindow::paintEvent(QPaintEvent *evt)
{

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
void GMainWindow::computeFile()
{
    QList<AbstractMatrixReader *> readers;
    //QList<QFileInfo> files = dir.entryInfoList(QStringList() << "*.txt", QDir::Files);
    //for(int i=0;i<files.size();i++){
        readers.append(new FileNumberStreamReader(m_fileName/*files.at(i).absoluteFilePath()*/));

       m_matrixManager.setReaders(readers);
       //m_matrixManager.setUseMultithread(useMultithread);
       m_matrixManager.run();
       m_coherenceManager.setMatrix(m_matrixManager.getResults());
       m_coherenceManager.run();
   // }
}

/**
 * Connecté au signal "computeFinished" du WordStatisticWorkerManager.
 * 
 * Lorsque ce slot est appelé il va récupérer  les résultats et les afficher dans la fenêtre
 * @return void
 */
void GMainWindow::computeFinished()
{
    QVector<QVector<QVector<float>>> resMatrix;
    resMatrix = m_matrixManager.getResults();

    for (int i=0 ;i< ui->tableWidget->rowCount();i++){
        for(int j=0 ; j< ui->tableWidget->columnCount(); j++)
        {
            QString tmp="[";
            for(int k=0; k<5; k++){
                tmp+=tr("%1;").arg(resMatrix[i][j][k]);
            }
            tmp+="]";
            QTableWidgetItem* itm = new QTableWidgetItem(tmp);

            ui->tableWidget->setItem(i,j,itm);
        }
    }

    //win->setShape(Line);
    QPen pen;
    pen.setWidth(20);
    pen.setCapStyle(Qt::RoundCap);
    pen.setColor(Qt::red);

    QList<QPoint *> res;
    res= m_coherenceManager.getResults();

    win.setPoints(res);
    win.resize(QSize(537,480));
    win.setPen(pen);
    win.setBrush(QBrush());
    win.show();

    /*//traitement pour afficher
    QPixmap pix("://Images/EEG 21.png");

    QPainter *painter = new QPainter(ui->QWidgetpaint);

    //painter->setRenderHints(QPainter::Antialiasing);
    QPen pen;
    pen.setWidth(100);
    pen.setCapStyle(Qt::RoundCap);
    pen.setColor(Qt::red);
    painter->setPen(pen);

    foreach(QPoint * line,res){

        painter->drawPoint(line[0]);
        //painter->drawPoint(line[1]);
        //painter->drawLine(line[0], line[1]);
    }
    painter->setBackground(pix);*/
}

void GMainWindow::setCoherenceRange(float min, float max)
{
    m_coherenceManager.setRange(min,max);
    computeFile();

}
