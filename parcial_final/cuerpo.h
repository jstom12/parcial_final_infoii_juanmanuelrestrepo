#ifndef CUERPO_H
#define CUERPO_H
#include <math.h>
#include <QGraphicsItem>
#include <QPainter>



class cuerpo: public QGraphicsItem
{
    float vx,vy,vel,angulo=20,posx,posy,r=10,delta=0.1,g=1;

public:
    cuerpo();
    cuerpo(float x, float y, float vel_);

    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = nullptr);

    void actualizar_velocidad();
    void actualizar_posicion();
};

#endif // CUERPO_H
