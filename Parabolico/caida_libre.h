#ifndef CAIDA_LIBRE_H
#define CAIDA_LIBRE_H
#include <QGraphicsItem>
#include <QPainter>


class caida_libre: public QGraphicsItem
{
    int posx , posy , r=10;
public:
    caida_libre();
    caida_libre(int x, int y);

    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = nullptr);

    void caida();
};

#endif // CAIDA_LIBRE_H
