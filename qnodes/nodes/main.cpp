#include "mainwindow.h"
#include <QApplication>
#include <string>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QFontDatabase::addApplicationFont(":/fonts/Ubuntu-Regular.ttf");
    MainWindow w;

    std::string in[] = {"in1","in2","in3"};
    std::string out[] = {"out1","out2"};

    w.getFlowEditor()->addNodeItem("AAA", in, 3, out, 2);
    //w.getFlowEditor()->addNodeItem("BBB", 2, 2);
    //w.getFlowEditor()->addNodeItem("CCC", 4, 1);
    //w.getFlowEditor()->addNodeItem("DDD", 1, 2);
    w.show();

    return a.exec();
}
