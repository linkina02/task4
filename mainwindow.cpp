#include "mainwindow.h"
#include "ui_mainwindow.h"

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

void MainWindow::on_runButton_clicked()
{
    QString word;
    QList<QString> synonyms;
    QList<QString> words;

    QList<QString> resultWords;

    QTextStream inputFileTextStream1(&fileInput1);
    QTextStream inputFileTextStream2(&fileInput2);

    if (!fileInput1.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        qDebug("Can`t open file");
    }

    if (!fileInput2.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        qDebug("Can`t open file");
    }

    while (!inputFileTextStream1.atEnd() && !inputFileTextStream1.atEnd())
    {
        word = inputFileTextStream1.readLine();
        words.append(word);
        QString line = inputFileTextStream2.readLine();
        synonyms = line.split(", ");
        table.insert(word, synonyms);
    }

    QString outPutFileName = QFileDialog::getSaveFileName(this, "Save file", defaultPath, "TXT Files (*.txt)");
    QFile outputFile(outPutFileName);

    if (!outputFile.open(QIODevice::WriteOnly | QIODevice::Text))
    {
        qDebug("Can`t save file");
    }

    QTextStream outputFileStream(&outputFile);

    QString outResult;
    QString wordsString;
    for (QString w : words) {
        QString synonym = replaceWithRandomSynonym(w, table);
        resultWords.append(synonym);
        wordsString.append(w + "\n");
        outResult.append(synonym + "\n");
        outputFileStream << synonym << "\n";
    }

    ui->logLabel->setText("Done");
    ui->outLabel->setText(outResult);
    ui->wordsLabel->setText(wordsString);
    fileInput1.close();
    fileInput2.close();
    outputFile.close();
}

void MainWindow::on_openFirstFile_clicked()
{
    QString fileName;
    fileName = QFileDialog::getOpenFileName(this, "Choose input file", defaultPath, "TXT Files (*.txt)");
    ui->firstNameLabel->setText(fileName);
    fileInput1.setFileName(fileName);
}


void MainWindow::on_openSecondFile_clicked()
{
    QString fileName;
    fileName = QFileDialog::getOpenFileName(this, "Choose synonym file", defaultPath, "TXT Files (*.txt)");
    ui->secondNameLabel->setText(fileName);
    fileInput2.setFileName(fileName);
}

