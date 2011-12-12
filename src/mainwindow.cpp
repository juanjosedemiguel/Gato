#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QKeyEvent"
#include <QMessageBox>
#include <Qt>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    gato = new Gato("Roberto", "VIKI", hombreVSAI, 1.0);
}

MainWindow::~MainWindow()
{
    delete ui;
}

    //QMessageBox::critical(this, "Titulo", "Texto", QMessageBox::Ok);

void MainWindow::keyPressEvent(QKeyEvent *event)
{
    Coordenada *coor = new Coordenada;
    switch (event->key())
    {
    case Qt::Key_Escape:
        break;
    case Qt::Key_1:
        coor->x = 0;
        coor->y = 2;
        gato->tirarJugador(uno, *coor);
        ui->pushButton_1->setText("X");
        *coor = gato->tirarMaquina();
        dibujarUI(coor->y, coor->x);
        break;
    case Qt::Key_2:
        coor->x = 1;
        coor->y = 2;
        gato->tirarJugador(uno, *coor);
        ui->pushButton_2->setText("X");
        *coor = gato->tirarMaquina();
        dibujarUI(coor->y, coor->x);
        break;
    case Qt::Key_3:
        coor->x = 2;
        coor->y = 2;
        gato->tirarJugador(uno, *coor);
        ui->pushButton_3->setText("X");
        *coor = gato->tirarMaquina();
        dibujarUI(coor->y, coor->x);
        break;
    case Qt::Key_4:
        coor->x = 0;
        coor->y = 1;
        gato->tirarJugador(uno, *coor);
        ui->pushButton_4->setText("X");
        *coor = gato->tirarMaquina();
        dibujarUI(coor->y, coor->x);
        break;
    case Qt::Key_5:
        coor->x = 1;
        coor->y = 1;
        gato->tirarJugador(uno, *coor);
        ui->pushButton_5->setText("X");
        *coor = gato->tirarMaquina();
        dibujarUI(coor->y, coor->x);
        break;
    case Qt::Key_6:
        coor->x = 2;
        coor->y = 1;
        gato->tirarJugador(uno, *coor);
        ui->pushButton_6->setText("X");
        *coor = gato->tirarMaquina();
        dibujarUI(coor->y, coor->x);
        break;
    case Qt::Key_7:
        coor->x = 0;
        coor->y = 0;
        gato->tirarJugador(uno, *coor);
        ui->pushButton_7->setText("X");
        *coor = gato->tirarMaquina();
        dibujarUI(coor->y, coor->x);
        break;
    case Qt::Key_8:
        coor->x = 1;
        coor->y = 0;
        gato->tirarJugador(uno, *coor);
        ui->pushButton_8->setText("X");
        *coor = gato->tirarMaquina();
        dibujarUI(coor->y, coor->x);
        break;
    case Qt::Key_9:
        coor->x = 2;
        coor->y = 0;
        gato->tirarJugador(uno, *coor);
        ui->pushButton_9->setText("X");
        *coor = gato->tirarMaquina();
        dibujarUI(coor->y, coor->x);
        break;
    default:
        break;
    }
}

void MainWindow::dibujarUI(int y, int x)
{
    if (y == 0)
    {
        if (x == 0)
            ui->pushButton_7->setText("O");
        else if (x == 1)
            ui->pushButton_8->setText("O");
        else
            ui->pushButton_9->setText("O");
    }
    else if (y == 1)
    {
        if (x == 0)
            ui->pushButton_4->setText("O");
        else if (x == 1)
            ui->pushButton_5->setText("O");
        else
            ui->pushButton_6->setText("O");
    }
    else
    {
        if (x == 0)
            ui->pushButton_1->setText("O");
        else if (x == 1)
            ui->pushButton_2->setText("O");
        else
            ui->pushButton_3->setText("O");
    }

}
