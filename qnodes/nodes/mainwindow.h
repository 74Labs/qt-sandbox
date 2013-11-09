#pragma once

#include <QMainWindow>
#include <QFlowEditor.h>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

    FlowEditor* getFlowEditor() const { return flowEditor; }
private slots:
    void flowNodeItemSelected();
    void flowNodeItemMoved();
    void flowNodeItemsConnected();
    void flowNodeItemsDisconnected();
private:
    QFlowEditor *flowEditor;
    Ui::MainWindow *ui;
};
