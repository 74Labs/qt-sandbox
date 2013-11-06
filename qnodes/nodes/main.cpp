#include "mainwindow.h"
#include <QApplication>

#include <QFlowEditorNode.h>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QFontDatabase::addApplicationFont(":/fonts/Ubuntu-Regular.ttf");
    MainWindow w;

    w.setFont(QFont("Ubuntu"));

    QFlowEditorNode *b = new QFlowEditorNode(QLatin1String("test"));
    w.getFlowEditor()->addItem(b);
    b->addPort("t1", 0);
    b->addInputPort("in1");
    b->addInputPort("in2");
    b->addInputPort("in3");
    b->addOutputPort("out1");
    b->addOutputPort("out2");
    b->addOutputPort("out3");

    for(int i = 0; i < 5; i ++) {
        b = b->clone();
        b->setPos(i * 175, 0);
    }

    w.show();

    return a.exec();
}
