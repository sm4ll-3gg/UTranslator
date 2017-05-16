#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "translator.h"

#include <QMainWindow>
#include <QStringList>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void    swapLangs();
    void    translate();

private: // Methods
    void    initUi();

private:
    Ui::MainWindow *ui;

    const QStringList fromLangs{"Русский"};
    const QStringList toLangs{"Английский"};

    Translator translator;
};

#endif // MAINWINDOW_H
