#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "chisla.h"
#include <QString>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

bool is_int(const QString &str) {
    QRegularExpression re("\\d+");
    return re.match(str).hasMatch();
}






void MainWindow::on_button_nod_nok_clicked()
{
    QString num1_str(ui->num1->text());
    QString num2_str(ui->num2->text());
    if (!is_int(num1_str) || !is_int(num2_str)) {
        ui->res1->setText("incorrect input");
        return;
    }
    int num1_int(num1_str.toInt());
    int num2_int(num2_str.toInt());
    number num1(num1_int);
    number num2(num2_int);
    if (ui->nod_or_nok->currentIndex() == 0)
    ui->res1->setText(QString::number(num1.nod(num2)));
    else ui->res1->setText(QString::number(num1.nok(num2)));
}


void MainWindow::on_button_simple_arm_clicked()
{
    QString num1_str(ui->num0->text());
    if (!is_int(num1_str)) {
        ui->res0->setText("incorrect input");
        return;
    }
    int num1_int(num1_str.toInt());
    number num1(num1_int);
    if (ui->simp_or_arm->currentIndex() == 0)
    ui->res0->setText(QString::number(num1.IsSimple()));
    else ui->res0->setText(QString::number(num1.is_Armstrong()));
}

