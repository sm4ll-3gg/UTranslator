#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "translator.h"
#include "Translators/rutoen.h"
#include <QStringList>
#include <QFile>
#include <QDebug>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    Translator t;
    t.translate("", Language::RU, Language::EN);
}

MainWindow::~MainWindow()
{
    delete ui;
}


