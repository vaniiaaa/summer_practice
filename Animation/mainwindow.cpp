#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QVBoxLayout>
#include <QTimer>
#include <cmath>
#include <QMouseEvent>

void MainWindow::moveParabola() {
        connect(anim_timer, &QTimer::timeout, [this]() {
        double x = a->get_t() * 10;
        double y = 0.01 * x * x;
        a->setPos(x, y);
        a->set_t(0.1);
    });
}

void MainWindow::moveLine() {

    connect(anim_timer, &QTimer::timeout, [this]() {
        double x = a->get_t() * 10;
        double y = a->get_t() * 10;
        a->setPos(x, y);
        a->set_t(0.1);
    });
}

void MainWindow::moveSinus() {
        connect(anim_timer, &QTimer::timeout, [this]() {

        double x = a->get_t() * 10;
        double y = 50 * sin(a->get_t());
        a->setPos(x, y);
        a->set_t(0.1);
    });
}



MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    scene = new QGraphicsScene(0, 0, 800, 600, this);
    ui->graphicsView->setScene(scene);
    scene->addRect(scene->sceneRect());

    a = new FalCirc(scene);
    scene->addItem(a);
    anim_timer = new QTimer(this);

    anim_timer->start(1000/60);
    connect(ui->btnParabola, &QPushButton::clicked, this, &MainWindow::moveParabola);
    connect(ui->btnLine, &QPushButton::clicked, this, &MainWindow::moveLine);
    connect(ui->btnSinus, &QPushButton::clicked, this, &MainWindow::moveSinus);

}
void MainWindow::mousePressEvent(QMouseEvent *event)
{
    if (event->button() == Qt::LeftButton) {
        QPointF scenePos = ui->graphicsView->mapToScene(event->pos());
        a->setPos(scenePos);


    }
    QMainWindow::mousePressEvent(event);
}
MainWindow::~MainWindow()
{
    delete ui;
}
FalCirc::FalCirc(QGraphicsScene* parent)
{
    main_widg = parent;
    setRect(200,200,20,20);
    setBrush(Qt::yellow);
    t=0;

}

void MainWindow::on_btnSinus_2_clicked()
{
    disconnect(anim_timer, nullptr, nullptr, nullptr);
    a->setPos(0,0);
    a->Reset();
}

