#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QString>
#include <QDir>
#include <QDirIterator>
#include <QVector>
#include <QAbstractTableModel>
#include <QStringListModel>
namespace fs = std::filesystem;

QStringList images;

void loadImagesList() {
    auto dir = QDir(fs::current_path().append("../input"));
    dir.setFilter(QDir::Filter::Files);
    auto iterator = QDirIterator(dir);
    while (iterator.hasNext()) {
        auto filename = QString::fromStdString(fs::path(iterator.next().toStdString()).filename().string());
        images.push_back(filename);
    }
}

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    loadImagesList();

    auto model = new QStringListModel(this);
    model->setStringList(images);
    ui->imagesList->setModel(model);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_startButton_clicked()
{
 qDebug() << "HI";
}

