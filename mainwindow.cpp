#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "Languages/rulang.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    RuLang::get();
}

MainWindow::~MainWindow()
{
    delete ui;
}
