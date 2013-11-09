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

    connect(flowEditor, SIGNAL(itemSelected()), this, SLOT(flowNodeItemSelected()));
    connect(flowEditor, SIGNAL(itemMoved()), this, SLOT(flowNodeItemMoved()));
    connect(flowEditor, SIGNAL(itemsConnected()), this, SLOT(flowNodeItemsConnected()));
    connect(flowEditor, SIGNAL(itemsDisconnected()), this, SLOT(flowNodeItemsDisconnected()));

    //setWindowFlags(Qt::FramelessWindowHint | Qt::CustomizeWindowHint);
    showFullScreen();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::flowNodeItemSelected()
{
    ui->statusBar->showMessage("Item selected");
}

void MainWindow::flowNodeItemMoved()
{
    ui->statusBar->showMessage("Item moved");
}

void MainWindow::flowNodeItemsConnected()
{
    ui->statusBar->showMessage("Items connected");
}

void MainWindow::flowNodeItemsDisconnected()
{
    ui->statusBar->showMessage("Items disconnected");
}
