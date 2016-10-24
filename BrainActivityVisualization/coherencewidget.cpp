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

void CoherenceWidget::paintEvent(QPaintEvent * /* event */)
{
    static const QPoint points[4] = {
        QPoint(10, 80),
        QPoint(20, 10),
        QPoint(80, 30),
        QPoint(90, 70)
    };

    QPainter painter(this);
    painter.setPen(pen);
    painter.setBrush(brush);
    painter.drawPoint(points[1]);
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
