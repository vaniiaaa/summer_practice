#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QMainWindow>
#include <QRegularExpression>
QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    friend class TestMainWindow;

private slots:

    void on_button_nod_nok_clicked();

    void on_button_simple_arm_clicked();

private:
    Ui::MainWindow *ui;

};
#endif // MAINWINDOW_H
