#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QGraphicsScene>
#include <particula.h>
#include <QMainWindow>
#include <QTimer>
#include <QList>

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

private:
    Ui::MainWindow *ui;
    QGraphicsScene *Scene;
    QTimer *timer;
    particula *cuerpo;
    QList<particula*> cuerpos;

};

#endif // MAINWINDOW_H
