#include "cuerpo.h"

cuerpo::cuerpo()
{

}

cuerpo::cuerpo(float x, float y, float vel_)
{
    posx = x;
    posy = y;
    vel = vel_;
}

QRectF cuerpo::boundingRect() const
{
    return QRectF(-r,-r,2*r,2*r);
}

void cuerpo::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->setBrush(Qt::blue);
    painter->drawEllipse(boundingRect());
}

void cuerpo::actualizar_velocidad()
{
    vx=vel*cos(angulo);
    vy=vel*sin(angulo)-g*delta;
    vel=sqrt(vy*vy+vx*vx);
    angulo=atan2(vy,vx);
}

void cuerpo::actualizar_posicion()
{
    posx+= vx*delta;
    posy+= vy*delta;
    setPos(posx,posy);
}
