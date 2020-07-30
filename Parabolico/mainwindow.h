#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QGraphicsScene>
#include <particula.h>
#include <QMainWindow>
#include <QTimer>
#include <QList>
#include <obstaculo.h>
#include<stdlib.h>
#include<time.h>


namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void Mover();

    void agregar_cuerpos_escena();

private:
    Ui::MainWindow *ui;
    QGraphicsScene *Scene;
    QTimer *timer;
    QTimer *agregar_cuerpos;
    particula *cuerpo;
    QList<particula*> cuerpos;
    QList<obstaculo*> rects;
    obstaculo *eliminacion;
    obstaculo *lat_der;
    obstaculo *lat_izq;

};

#endif // MAINWINDOW_H
