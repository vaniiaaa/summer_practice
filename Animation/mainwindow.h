#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsItem>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
class FalCirc: public QGraphicsEllipseItem
{
public:
    FalCirc(QGraphicsScene* parent);
    QGraphicsScene* main_widg;
    void Reset() {
        x0=y0=x1=y1=t=0;
    }
    void set_t() {
        t = 0;
    }
    void set_t(double _t) {
        t += _t;
    }
    double get_t() {
        return t;
    }
private:
    double t;
    double x0, y0, x1, y1;

};

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
private slots:
    void moveParabola();
    void moveLine();
    void moveSinus();

    void mousePressEvent(QMouseEvent *event);
    void on_btnSinus_2_clicked();

private:
    Ui::MainWindow *ui;
    QGraphicsScene* scene;
    QTimer* anim_timer;
    FalCirc* a;
    FalCirc* b;
};
#endif // MAINWINDOW_H
