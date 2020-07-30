#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    scene = new QGraphicsScene(0,0,780,580);
    ui->graphicsView->setScene(scene);
    scene->backgroundBrush();
    ui->graphicsView->setBackgroundBrush(QPixmap(":/new/prefix1/resources/aguacate.png"));
    timer = new QTimer();
    cuerpos.push_back(new cuerpo(0,0,50));
    scene->addItem(cuerpos.back());
    connect(timer,SIGNAL(timeout()),this,SLOT(procesos()));
    timer->start(30);

}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::procesos()
{
    QList<cuerpo*>::iterator it;
    for(it=cuerpos.begin();it!=cuerpos.end();it++)
    {
        (*it)->actualizar_velocidad();
        (*it)->actualizar_posicion();
    }
}
