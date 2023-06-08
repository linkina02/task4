#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtCore/QFile>
#include <QtCore/QTextStream>
#include <QtCore/QMap>
#include <QtCore/QList>
#include "qfiledialog.h"
#include "synonymdictionary.h"


QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_runButton_clicked();

    void on_openFirstFile_clicked();

    void on_openSecondFile_clicked();

private:
    Ui::MainWindow *ui;
    QFile fileInput1;
    QFile fileInput2;
    SynonymTable table;
    QString defaultPath = "C:\\Users\\пк\\Documents\\task4";
};
#endif // MAINWINDOW_H
