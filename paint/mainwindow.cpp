#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QColorDialog> 
#include <QFileDialog>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    scene = new paintScene();       // Инициализируем графическую сцену
    ui->graphicsView->setScene(scene);  // Устанавливаем графическую сцену
    ui->graphicsView->setRenderHint(QPainter::Antialiasing);                // Устанавливаем сглаживание

    timer = new QTimer();       // Инициализируем таймер
    connect(timer, &QTimer::timeout, this, &MainWindow::slotTimer);
    timer->start(100);

}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::slotTimer()
{
    timer->stop();
    scene->setSceneRect(0,0, ui->graphicsView->width() - 20, ui->graphicsView->height() - 20);
}

void MainWindow::resizeEvent(QResizeEvent *event)
{
    timer->start(100);
    QWidget::resizeEvent(event);
}

void MainWindow::on_actionRed_triggered()
{
    scene->setPenColor(Qt::red);
    scene->setDrawMode(paintScene::ModeDraw);
}

void MainWindow::on_actionGreen_triggered()
{
    scene->setPenColor(Qt::green);
    scene->setDrawMode(paintScene::ModeDraw);
}

void MainWindow::on_actionBlue_triggered()
{
    scene->setPenColor(Qt::blue);
    scene->setDrawMode(paintScene::ModeDraw);
}

void MainWindow::on_actionClear_triggered()
{
    scene->clear();
}

void MainWindow::on_actionCustomColor_triggered()
{
    QColor color = QColorDialog::getColor(Qt::white, this, "Select Color");
    if (color.isValid()) {
        scene->setPenColor(color);
        scene->setDrawMode(paintScene::ModeDraw);
    }
}

void MainWindow::on_actionSquare_triggered()
{
    scene->setTypeFigure(paintScene::SquareType);
    scene->setDrawMode(paintScene::ModeFigure);
}

void MainWindow::on_actionRomb_triggered()
{
    scene->setTypeFigure(paintScene::RombType);
    scene->setDrawMode(paintScene::ModeFigure);
}

void MainWindow::on_actionTriangle_triggered()
{
    scene->setTypeFigure(paintScene::TriangleType);
    scene->setDrawMode(paintScene::ModeFigure);
}

void MainWindow::on_actionSave_triggered()
{
    QString filePath = QFileDialog::getSaveFileName(this, "Save File", "", "Text Files (*.txt)");
    if (!filePath.isEmpty()) {
        scene->saveToFile(filePath);
    }
}

void MainWindow::on_actionLoad_triggered()
{
    QString filePath = QFileDialog::getOpenFileName(this, "Load File", "", "Text Files (*.txt)");
    if (!filePath.isEmpty()) {
        scene->loadFromFile(filePath);
    }
}



