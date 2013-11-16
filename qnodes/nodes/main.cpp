#include "mainwindow.h"
#include <QApplication>

#include <string>

#include <FlowManager.h>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QFontDatabase::addApplicationFont(":/fonts/awesome");
    MainWindow w;
    //w.setFont(QFont("Roboto Condensed"));

    sfl::flow::FlowManager fm(w.getFlowEditor());

    fm.createNode("HTTP src")->addNodeOutputPin("out1", "http")->addNodeOutputPin("out2", "http");
    fm.createNode("HTTP dest")->addNodeInputPin("in1", "http");
    fm.createNode("CORE dest")->addNodeInputPin("in1", "");
    fm.createNode("CORE src")->addNodeOutputPin("out1", "");

    return a.exec();
}
