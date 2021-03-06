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
    m_coherenceManager.setRange(0,0.1);   // VALEUR PAR DEFAUT A MODIFIER !!!!!!
    ui->lineEditMiniRange->setText("0");  // min
    ui->lineEditMaxRange->setText("0.1");   // max
    //win = new CoherenceWidget(this);

    connect(&m_coherenceManager,SIGNAL(computeFinishedTotally()),this,SLOT(computeFinished()));
    connect(ui->actionOpen,SIGNAL(triggered(bool)),this,SLOT(openFile()));
    connect(&m_matrixManager, SIGNAL(progressChanged(int)), ui->progressBar, SLOT(setValue(int)));
    connect(&m_matrixManager, SIGNAL(progressRangeChanged(int,int)), ui->progressBar, SLOT(setRange(int,int)));
    connect(ui->pushButtonUp, SIGNAL(clicked(bool)), this, SLOT(setCoherenceRange(bool)));

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

       readers.append(new FileNumberStreamReader(m_fileName));

       m_matrixManager.setReaders(readers);
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

    QPen pen;
    pen.setWidth(2);
    pen.setCapStyle(Qt::RoundCap);
    int cpt_col=0;
    int cpt_row=0;
    int nb_res = 0;
    QVector<QList<QVector<QPoint>>> res;
    QVector<CoherenceWidget*> win;
    res= m_coherenceManager.getResults();
    for(int i = 0;i<res.size();i++){
        if(i==0){
            win.append(new CoherenceWidget(m_fileName.split("/").last()+" - Delta"));
            pen.setColor(Qt::red);
        }else if(i==1){
            win.append(new CoherenceWidget(m_fileName.split("/").last()+" - Theta"));
            pen.setColor(Qt::green);
        }else if(i==2){
            win.append(new CoherenceWidget(m_fileName.split("/").last()+" - Alpha"));
            pen.setColor(Qt::blue);
        }else if(i==3){
            win.append(new CoherenceWidget(m_fileName.split("/").last()+" - Beta"));
            pen.setColor(Qt::yellow);
        }else {
            win.append(new CoherenceWidget(m_fileName.split("/").last()+" - Gamma"));
            pen.setColor(Qt::gray);
        }
        win[i]->move(cpt_col*537,cpt_row*537);
        win[i]->setPoints(res[i]);
        win[i]->setMinimumSize(537,480);
        win[i]->setMaximumSize(537,480);
        win[i]->setPen(pen);
        win[i]->setBrush(QBrush());
        win[i]->show();
        nb_res+=res[i].size();
        cpt_col++;
        if(cpt_col==3){
            cpt_row++;
            cpt_col=0; //int tab[x][Y][Z]   // tab[0][0][0] =300 ;
        }
    }

    ui->value_number->setText(QString::number(nb_res));

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

void GMainWindow::setCoherenceRange(bool e)
{
    m_coherenceManager.setRange(ui->lineEditMiniRange->text().toFloat(),ui->lineEditMaxRange->text().toFloat());
    m_matrixManager.raz();
    m_coherenceManager.raz();
    computeFile();

}
