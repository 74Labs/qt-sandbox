#pragma once

#include <QGraphicsView>
#include <QFont>
#include <QGraphicsScene>
#include <QEvent>
#include <QGraphicsSceneMouseEvent>
#include <QFontDatabase>

#include <FlowEditor.h>

class QFlowEditorPinConnection;

class QFlowEditor : public QGraphicsView, public FlowEditor
{
    Q_OBJECT
public:

    explicit QFlowEditor(QWidget *parent = 0);

    virtual ~QFlowEditor();

    void addNodeItem(Node *node);

    /*
    void addNodeItem(const std::string& name, std::vector<std::string>& inputPins, std::vector<std::string>& outputPins);
    void addNodeItem(const std::string& name, std::string inputPins[], unsigned int inputPinsCount, std::string outputPins[], unsigned int outputPinsCount);
    void addNodeItem(const std::string& name, unsigned int inputPins, unsigned int outputPins);
    void addNodeItem(const std::string& name, NodePinList& inputPins, NodePinList& outputPins);
    */
    bool eventFilter(QObject *, QEvent *);

signals:

    void itemSelected();
    void itemMoved();
    void itemsConnected();
    void itemsDisconnected();

private:

	QGraphicsItem *itemAt(const QPointF&);

private:
	QGraphicsScene *scene;
    QFont font;
    QFlowEditorPinConnection *conn;
	// QNEBlock *selBlock;
};
