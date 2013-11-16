#pragma once

#include <QGraphicsView>
#include <QFont>
#include <QGraphicsScene>
#include <QEvent>
#include <QGraphicsSceneMouseEvent>
#include <QFontDatabase>

#include <FlowEditor.h>
#include <Node.h>

class QFlowEditorNodeItem;
class QFlowEditorPinConnection;

class QFlowEditor : public QGraphicsView, public sfl::flow::FlowEditor
{
    Q_OBJECT
public:

    explicit QFlowEditor(QWidget *parent = 0);

    virtual ~QFlowEditor();

    sfl::flow::FlowEditorNodeItem* createNodeItem(sfl::flow::Node *node);
    void deleteNodeItem(sfl::flow::Node *node);

    std::vector<sfl::flow::FlowEditorNodeItem*> getItems();

    /*
    void addNodeItem(const std::string& name, std::vector<std::string>& inputPins, std::vector<std::string>& outputPins);
    void addNodeItem(const std::string& name, std::string inputPins[], unsigned int inputPinsCount, std::string outputPins[], unsigned int outputPinsCount);
    void addNodeItem(const std::string& name, unsigned int inputPins, unsigned int outputPins);
    void addNodeItem(const std::string& name, NodePinList& inputPins, NodePinList& outputPins);
    */
    bool eventFilter(QObject *, QEvent *);

private:

	QGraphicsItem *itemAt(const QPointF&);

private:
	QGraphicsScene *scene;
    QFont font;
    QFlowEditorPinConnection *conn;
	// QNEBlock *selBlock;
};
