#include "coherencewidget.h"

#include <QPainter>
#include <QPainterPath>

CoherenceWidget::CoherenceWidget()
    : QWidget()
{
    shape = Polygon;
    antialiased = false;
    transformed = false;
    pixmap.load(":/Images/EEG 21.png");

    //setBackgroundRole(QPalette::Base);
    //setAutoFillBackground(true);
}

CoherenceWidget::CoherenceWidget(QString name): QWidget()
{
    this->setWindowTitle(name);
    shape = Polygon;
    antialiased = false;
    transformed = false;
    pixmap.load(":/Images/EEG 21.png");
}


void CoherenceWidget::paintEvent(QPaintEvent * /* event */)
{

    QPainter painter(this);
    painter.setPen(pen);
    painter.setBrush(brush);
    foreach(QVector<QPoint> line,m_points){
        painter.drawPoint(line[0]);
        painter.drawPoint(line[1]);
        painter.drawLine(line[0], line[1]);
    }
    pixmap = pixmap.scaled(this->size(),Qt::IgnoreAspectRatio);
    QPalette palette;
    palette.setBrush(QPalette::Background,pixmap);
    this->setPalette(palette);
    //painter.setBackground(pixmap);
}
QSize CoherenceWidget::sizeHint() const
{
    return QSize(400, 200);
}

void CoherenceWidget::setPoints(QList<QVector<QPoint>> points)
{
    m_points = points;
}
QSize CoherenceWidget::minimumSizeHint() const
{
    return QSize(100, 100);
}
void CoherenceWidget::setShape(Shape shape)
{
    this->shape = shape;
    update();
}

void CoherenceWidget::setPen(const QPen &pen)
{
    this->pen = pen;
    update();
}

void CoherenceWidget::setBrush(const QBrush &brush)
{
    this->brush = brush;
    update();
}
void CoherenceWidget::setAntialiased(bool antialiased)
{
    this->antialiased = antialiased;
    update();
}

void CoherenceWidget::setTransformed(bool transformed)
{
    this->transformed = transformed;
    update();
}
