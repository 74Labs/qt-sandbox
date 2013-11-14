#include "mainwindow.h"
#include <QApplication>

#include <vector>
#include <string>
#include <iostream>

#include <FlowManager.h>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    //QFontDatabase::addApplicationFont(":/fonts/roboto");
    MainWindow w;

    //w.setFont(QFont("Roboto Condensed"));

    std::vector<std::string> in;
    in.push_back("in1");
    in.push_back("in2");

    std::vector<std::string> out;
    out.push_back("out1");

    FlowManager fm(w.getFlowEditor());
    //NodeType* nodeTmpl = fm.addNodeTemplate("template");
    //nodeTmpl->getInputPins().push_back({"in1"});

    Node node1("HTTP src");
    node1.addNodeOutputPin("out1", "http");
    node1.addNodeOutputPin("out2", "http");
    Node node2("HTTP dest");
    node2.addNodeInputPin("in1", "http");

    fm.addNode(&node1);
    fm.addNode(&node2);

    //MockNode nodeMock("mock");

    //w.getFlowEditor()->addNodeItem(&nodeMock);

    //w.getFlowEditor()->addNodeItem("BBB", 2, 2);
    //w.getFlowEditor()->addNodeItem("CCC", 4, 1);
    //w.getFlowEditor()->addNodeItem("DDD", 1, 2);
    //w.show();

    return a.exec();
}
