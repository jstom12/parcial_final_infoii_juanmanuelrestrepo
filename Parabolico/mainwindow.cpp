
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
    rects.push_back(new obstaculo (-300,-60,20,60));
    Scene->addItem(rects.back());

    eliminacion = new obstaculo (0,-100,10,390);
    Scene->addItem(eliminacion);
    lat_der = new obstaculo (-380,180,290,10);
    Scene->addItem(lat_der);
    lat_izq = new obstaculo (0,180,290,10);
    Scene->addItem(lat_izq);

    connect(timer,SIGNAL(timeout()),this,SLOT(Mover()));
    connect(agregar_cuerpos,SIGNAL(timeout()),this,SLOT(agregar_cuerpos_escena()));
    timer->start(30);
    agregar_cuerpos->start(1000);
}

MainWindow::~MainWindow()
{
    delete ui;
}



void MainWindow::Mover()
{
    for(QList<caida_libre*>::iterator it_1=caidas.begin();it_1!=caidas.end();it_1++)
    {
        (*it_1)->caida();
    }
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
            if((*it)->collidesWithItem(eliminacion))
            {
                int pos = cuerpos.indexOf((*it));
                Scene->removeItem(cuerpos.at(pos));
                cuerpos.removeAt(pos);
                return;
            }
            if((*it)->collidesWithItem(lat_der) || ((*it)->collidesWithItem(lat_izq)))
            {
               (*it)->setVx(-(*it)->getVx());
               (*it)->ActualizarPosicion();
            }
        }
    }

}

void MainWindow::agregar_cuerpos_escena()
{
    int an, x , y , velocidad;
    srand(time(NULL));
    x = 1+rand()%(101-1);
    y = 1+rand()%(101-1);
    an = 1+rand()%50;
    velocidad = 1+rand()%(101-1);
    cuerpos.push_back(new particula((an/180)*3.1415, x, y, velocidad));
    Scene->addItem(cuerpos.back());
}


void MainWindow::on_pushButton_clicked()
{
    int x= ui->lineEdit->text().toDouble();
    int y= ui->lineEdit_2->text().toDouble();
    caidas.push_back(new caida_libre (x,y));
    Scene->addItem(caidas.back());

}
