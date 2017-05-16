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
    initUi();

    connect(ui->swapButton, &QPushButton::clicked,
            this, &MainWindow::swapLangs);
    connect(ui->translateButton, &QPushButton::clicked,
            this, &MainWindow::translate);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::swapLangs()
{
    QString currFromLang = ui->fromLangBox->currentText();
    QString currToLang = ui->toLangBox->currentText();
    if(fromLangs.contains(currToLang) &&
            toLangs.contains(currFromLang))
    {
        ui->fromLangBox->setCurrentText(currToLang);
        ui->toLangBox->setCurrentText(currFromLang);

        QString currFromText = ui->fromLangText->toPlainText();
        ui->fromLangText->setPlainText( ui->toLangText->toPlainText() );
        ui->toLangText->setPlainText(currFromText);
    }
    else
    {
        QString message = "К сожалению, " + currToLang +
                " язык не может быть переведен на " +
                currFromLang;
        ui->statusBar->showMessage(message, 5000);
    }
}

void MainWindow::translate()
{
    QString text = ui->fromLangText->toPlainText().toLower();
    QString fromLang = ui->fromLangBox->currentText();
    QString toLang = ui->toLangBox->currentText();

    QString translation = translator.translate(text,
                                               Language::languages.value(fromLang),
                                               Language::languages.value(toLang));
    ui->toLangText->setPlainText(translation);
}

void MainWindow::initUi()
{
    ui->fromLangBox->addItems(fromLangs);
    ui->toLangBox->addItems(toLangs);
}


