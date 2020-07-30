#ifndef OBSTACULO_H
#define OBSTACULO_H
#include <QGraphicsItem>
#include <QPainter>


class obstaculo: public QGraphicsItem
{
    int posx,posy,h,w;

public:
    obstaculo();
    obstaculo(int x, int y, int h_ , int w_);

    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = nullptr);
};

#endif // OBSTACULO_H
