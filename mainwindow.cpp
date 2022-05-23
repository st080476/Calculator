#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QRegularExpression>
#include <QMessageBox>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->radioButton_3->setChecked(true);


}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{
    int operation = ui->comboBox->currentIndex();
    bool minus = ui->checkBox->checkState();
    int max = 10;
    if(ui->radioButton_3->isChecked()){
        max = 10;
    } else if(ui->radioButton_2->isChecked()){
        max = 100;
    } else if (ui->radioButton->isChecked()){
        max = 1000;
    }

    QString text = ui->lineEdit->text();
    QString text2 = ui->lineEdit_2->text();

    QString textR = text;
    QString text2R = text2;

    if(textR.isEmpty() ||text2.isEmpty()){
        QMessageBox::warning(this, "Ошибка", "Пустая строка");
        return;
    }

    if(textR[0] == '-' ){
        textR.remove(0, 1);
    }

    if(text2R[0] == '-' ){
        text2R.remove(0, 1);
    }

    if(textR.isEmpty() ||text2.isEmpty()){
        QMessageBox::warning(this, "Ошибка", "Пустая строка");
        return;
    }

    QRegularExpression re("[^\\d]{1,}");  // a digit (\d), zero or more times (*)
    if (re.match(textR).hasMatch() || re.match(text2R).hasMatch()){
        QMessageBox::warning(this, "Ошибка", "вводите только числа");
        return;
    }

    double num1 = text.toDouble();
    double num2 = text2.toDouble();

    if (!minus &&(num1 < 0 || num2 < 0) ){
       QMessageBox::warning(this, "Ошибка", "отрицательное число");
        return;
    }

    if(abs(num1) > max || abs(num2) > max){
        QMessageBox::warning(this, "Ошибка", QString("Диапазон чисел от 0 до %0").arg(max));

        return;
    }
    double result = 0;
    switch (operation) {
    case 0:
        result = num1+num2;
        break;
    case 1:
        result = num1-num2;
        break;
    case 2:
        result = num1*num2;
        break;
    case 3:
        result = num1/num2;
        break;


    default:
        break;
    }

    ui->label_6->setText(QString("%0").arg(result));

}

