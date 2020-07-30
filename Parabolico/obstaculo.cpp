#include "obstaculo.h"

obstaculo::obstaculo()
{

}

obstaculo::obstaculo(int x, int y, int h_, int w_)
{
    posx = x;
    posy = y;
    h = h_;
    w = w_;
}

QRectF obstaculo::boundingRect() const
{
    return QRect(-posx,-posy,w,h);
}

void obstaculo::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->setBrush(Qt::yellow);
    painter->drawRect(boundingRect());
}
