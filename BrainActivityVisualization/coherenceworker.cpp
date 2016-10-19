#include "coherenceworker.h"

CoherenceWorker::CoherenceWorker()
{

    QVector<QVector<QVector<float>>> tmp_dim1(20);
    m_matrix.append(tmp_dim1);
    for(int i=0;i<20;i++)
    {
        QVector<QVector<float>> tmp_dim2(20);
        m_matrix[i].append(tmp_dim2);
        for(int j=0;j<20;j++)
        {
            QVector<float> tmp_dim3(5,0.0);
            m_matrix[i][j].append(tmp_dim3);
        }

    }
}

CoherenceWorker::~CoherenceWorker()
{

}
void CoherenceWorker::setReader(AbstractMatrixReader *reader)
{
    m_reader = reader;
}
const QVector<QVector<QVector<float>>> CoherenceWorker::getResults() const
{
    return m_matrix;
}
void CoherenceWorker::compute()
{
    float nb;
    bool ok = false;
    if(m_reader->open()) {
        ok= true;
        for(int i=0;i<20;i++){
            for(int j=0;j<20;j++){
                for(int k=0;k<5;k++){
                    m_reader->readNumber(nb);
                    m_matrix[i][j][k]=nb;
                }
            }
        }
        m_reader->close();
    } ;
}
