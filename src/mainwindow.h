#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "gato.h"
#include <QMainWindow>

namespace Ui {
    class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

protected:
    void keyPressEvent(QKeyEvent *event);

private slots:
    void on_pushButton_clicked();

private:
    Ui::MainWindow *ui;
    Gato *gato;
    void dibujarUI(int y, int x);
};

#endif // MAINWINDOW_H
