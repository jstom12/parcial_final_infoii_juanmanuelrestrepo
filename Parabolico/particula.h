#ifndef PARTICULA_H
#define PARTICULA_H
#include <math.h>
#include <QGraphicsItem>
#include <QPainter>
#include <QDebug>


class particula: public QGraphicsItem
{
    double angulo,posy,posx,vx,vy,vel;
    double g = 9.8;
    double delta=0.1;
    int r=10;

public:
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = Q_NULLPTR);
    particula();
    particula(double a, double x, double y, double v);
    void ActualizarPosicion();
    void CalcularVelicidad();

    double getPosy() const;
    double getPosx() const;
    double getVy() const;
    void setVy(double value);
};

#endif // PARTICULA_H
