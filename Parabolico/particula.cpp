#include "particula.h"

double particula::getPosy() const
{
    return posy;
}

double particula::getPosx() const
{
    return posx;
}

double particula::getVy() const
{
    return vy;
}

void particula::setVy(double value)
{
    vy = value;
}

double particula::getVx() const
{
    return vx;
}

void particula::setVx(double value)
{
    vx = value;
}

QRectF particula::boundingRect() const
{
    return QRectF(-r,-r,2*r,2*r);
}

void particula::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->setBrush(Qt::cyan);
    painter->drawEllipse(boundingRect());
}

particula::particula()
{

}

particula::particula(double a, double x, double y, double v)
{
    angulo=a;
    posx=x;
    posy=y;
    vel=v;
    setPos(posx,-posy);

}

void particula::ActualizarPosicion()
{
    posx+=vx*delta;
    posy+=vy*delta-0.5*g*delta*delta;
    setPos(posx,-posy);
    qDebug()<<"Posx= "<<posx<<" Posy=" <<posy<<endl;

}

void particula::CalcularVelicidad()
{
    vx=vel*cos(angulo);
    vy=vel*sin(angulo)-g*delta;
    vel=sqrt(vy*vy+vx*vx);
    angulo=atan2(vy,vx);

}
