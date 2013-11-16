#pragma once

#include <QMainWindow>
#include <QFlowEditor.h>

#include <Node.h>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

    sfl::flow::FlowEditor* getFlowEditor() const { return flowEditor; }

private:
    QFlowEditor *flowEditor;
    Ui::MainWindow *ui;
};
