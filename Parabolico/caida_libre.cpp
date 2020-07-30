#include "caida_libre.h"

caida_libre::caida_libre()
{

}

caida_libre::caida_libre(int x, int y)
{
    posx = x;
    posy = y;
    setPos(posx,posy);
}

QRectF caida_libre::boundingRect() const
{
    return QRectF(-r,-r,2*r,2*r);
}

void caida_libre::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->setBrush(Qt::red);
    painter->drawEllipse(boundingRect());
}

void caida_libre::caida()
{
    posy -= 5;
    setPos(posx,posy);
}
