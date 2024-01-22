#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFile>
#include <QDebug>
#include <QTextStream>
#include <QGridLayout>

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent) {
    text_field = new QTextEdit(this);
    button_generate = new QPushButton("TAP TO GENERATE KEY");
    centr_wid = new QWidget(this);
    setCentralWidget(centr_wid);
    QVBoxLayout *mainLayout = new QVBoxLayout(centr_wid);
    mainLayout->addWidget(text_field);
    mainLayout->addWidget(button_generate);
    connect(button_generate, &QPushButton::clicked, this, &MainWindow::on_pushButton_clicked);
}

MainWindow::~MainWindow() {}

void MainWindow::on_pushButton_clicked() {
    QString keyFile = "private.key";
    int result = system("openssl genpkey -algorithm gost2012_256 -pkeyopt paramset:A -out private.key");
    if (!result) {
        QFile file(keyFile);
        if (file.open(QIODevice::ReadOnly | QIODevice::Text)) {
            QTextStream in(&file);
            key = in.readAll();
            file.close();
        }

        else
            qDebug() << "ERROR OF OPENING FILE: " << keyFile;

    }

    else
        qDebug() << "ERROR OF KEY GENERATION!";

   this->text_field->setText(key);
}
