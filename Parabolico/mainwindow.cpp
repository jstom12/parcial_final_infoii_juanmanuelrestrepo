
#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    Scene= new QGraphicsScene;
    timer= new QTimer;
    ui->graphicsView->setScene(Scene);
    Scene->setSceneRect(0,-180,390,290);
    Scene->addRect(Scene->sceneRect());
    cuerpos.push_back(new particula((35/180)*3.1415, 100, 100, 50));
    Scene->addItem(cuerpos.back());

  connect(timer,SIGNAL(timeout()),this,SLOT(Mover()));
  timer->start(30);
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
}

