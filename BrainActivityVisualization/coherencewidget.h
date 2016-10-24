#ifndef COHERENCEWIDGET_H
#define COHERENCEWIDGET_H
#include <QPaintEvent>
#include <QPen>
#include <QWidget>
#include <QList>



class CoherenceWidget : public QWidget
{
    Q_OBJECT

public:
    CoherenceWidget();
    enum Shape { Line, Points, Polyline, Polygon, Rect, RoundedRect, Ellipse, Arc,
                 Chord, Pie, Path, Text, Pixmap };

    RenderArea(QWidget *parent = 0);

    QSize minimumSizeHint() const;
    QSize sizeHint() const;
    void setPoints(QList<QPoint*>points);
public slots:
    void setShape(Shape shape);
    void setPen(const QPen &pen);
    void setBrush(const QBrush &brush);
    void setAntialiased(bool antialiased);
    void setTransformed(bool transformed);

protected:
    void paintEvent(QPaintEvent *event);

private:
    Shape shape;
    QPen pen;
    QBrush brush;
    bool antialiased;
    bool transformed;
    QPixmap pixmap;
    QList<QPoint *> m_points;
};

#endif // COHERENCEWIDGET_H
