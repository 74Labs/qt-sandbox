#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    flowEditor = new QFlowEditor(ui->centralWidget);
    flowEditor->setRenderHint(QPainter::Antialiasing, true);
    ui->centralWidget->layout()->addWidget(flowEditor);

    //setWindowFlags(Qt::FramelessWindowHint | Qt::CustomizeWindowHint);
    showFullScreen();
}

MainWindow::~MainWindow()
{
    delete ui;
}
