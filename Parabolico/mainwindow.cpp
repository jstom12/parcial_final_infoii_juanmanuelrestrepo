
#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    Scene= new QGraphicsScene;
    timer= new QTimer;
    agregar_cuerpos = new QTimer;
    ui->graphicsView->setScene(Scene);
    Scene->setSceneRect(0,-180,390,290);
    Scene->addRect(Scene->sceneRect());


    rects.push_back(new obstaculo (-60,-60,20,80));
    Scene->addItem(rects.back());
    rects.push_back(new obstaculo (-300,-60,20,80));
    Scene->addItem(rects.back());

    connect(timer,SIGNAL(timeout()),this,SLOT(Mover()));
    connect(agregar_cuerpos,SIGNAL(timeout()),this,SLOT(agregar_cuerpos_escena()));
    timer->start(30);
    agregar_cuerpos->start(100);
}

MainWindow::~MainWindow()
{
    delete ui;
}



void MainWindow::Mover()
{
    for(QList<particula*>::iterator it=cuerpos.begin(); it!=cuerpos.end();it++)
    {
        (*it)->CalcularVelicidad();
        (*it)->ActualizarPosicion();
    }
    QList<particula*>::iterator it;
    QList<obstaculo*>::iterator itm;
    for(it=cuerpos.begin();it!=cuerpos.end();it++)
    {
        for(itm=rects.begin();itm!=rects.end();itm++)
        {
            if((*it)->collidesWithItem((*itm)))
            {
                (*it)->setVy(-(*it)->getVy());
                (*it)->ActualizarPosicion();
            }
        }
    }
}

void MainWindow::agregar_cuerpos_escena()
{
    cuerpos.push_back(new particula((35/180)*3.1415, 100, 100, 50));
    Scene->addItem(cuerpos.back());
}

