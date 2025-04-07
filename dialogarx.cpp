#include "dialogarx.h"
#include "ui_dialogarx.h"

DialogARX::DialogARX(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::DialogARX)
{
    ui->setupUi(this);
}
DialogARX::~DialogARX()
{
    delete ui;
}

std::vector<double> DialogARX::getA()
{
    std::vector<double> values;

    QString text = ui->lineEdit->text();
    QStringList strList = text.split(";", Qt::SkipEmptyParts);

    // Convert each string to double and add to QVector
    for (const QString &str : strList) {
        bool ok;
        double num = str.toDouble(&ok);
        if (ok) { // Only add valid numbers
            values.push_back(num);
        }
    }

    return values;
}
std::vector<double> DialogARX::getB()
{
    std::vector<double> values;

    QString text = ui->lineEdit_2->text();
    QStringList strList = text.split(";", Qt::SkipEmptyParts);

    // Convert each string to double and add to QVector
    for (const QString &str : strList) {
        bool ok;
        double num = str.toDouble(&ok);
        if (ok) { // Only add valid numbers
            values.push_back(num);
        }
    }

    return values;
}

int DialogARX::getK()
{
    return ui->spinBox->value();
}
double DialogARX::getNoise()
{
    return ui->doubleSpinBox->value();
}

QString DialogARX::getATextField()
{
    return ui->lineEdit->text();
}

QString DialogARX::getBTextField()
{
    return ui->lineEdit_2->text();
}


void DialogARX::setATextField(QString text)
{
    ui->lineEdit->setText(text);
}

void DialogARX::setBTextField(QString text)
{
    ui->lineEdit_2->setText(text);
}

void DialogARX::setKField(int k)
{
    ui->spinBox->setValue(k);
}
void DialogARX::setNoiseField(double noise)
{
    ui->doubleSpinBox->setValue(noise);
}
void DialogARX::on_pushButton_clicked()
{
    if (ui->lineEdit->text() != "" && ui->lineEdit_2->text() != ""){
        accept();
    }
}


void DialogARX::on_pushButton_2_clicked()
{
    reject();
}

