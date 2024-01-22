#ifndef MAINWINDOW_H

#define MAINWINDOW_H

#include <QMainWindow>
#include <QTextEdit>
#include <QPushButton>
#include <QVBoxLayout>
#include <QLabel>

class MainWindow : public QMainWindow {

    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    QString key;

private slots:
    void on_pushButton_clicked();

private:
    QTextEdit* text_field;
    QPushButton* button_generate;
    QWidget* centr_wid;
};

#endif // MAINWINDOW_H
