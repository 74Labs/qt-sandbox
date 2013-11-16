#pragma once

#include <Node.h>
#include <NodeType.h>

#include <FlowEditorNodeItem.h>

#include <sfl/Observable.h>

namespace sfl {

namespace flow {

class FlowEditor;

class FlowEditorEvents {
private:
    class BaseEvent {
    public:
        FlowEditor* editor;
    public:
        BaseEvent(FlowEditor* editor) { this->editor = editor; }
    };

    class BaseBeforeEvent : public BaseEvent {
    public:
        FlowEditor* editor;
        bool isRejected;
    public:
        BaseBeforeEvent(FlowEditor* editor) : BaseEvent(editor), isRejected(false) {}
    };

    class NodeEvent {
    public:
        Node* node;
    public:
        NodeEvent(Node* node) : node(node) {}
    };

    class NodesConnectionEvent {
    public:
        NodePin* sourceNodePin;
        NodePin* destinationNodePin;
    public:
        NodesConnectionEvent(NodePin* sourceNodePin, NodePin* destinationNodePin) : sourceNodePin(sourceNodePin), destinationNodePin(destinationNodePin) {}
    };

public:

    class NodeSelectedEvent : public BaseEvent, public NodeEvent {
    public:
        NodeSelectedEvent(FlowEditor* editor, Node* node) : BaseEvent(editor), NodeEvent(node) {}
    };

    class BeforeNodesConnectedEvent : public BaseBeforeEvent, public NodesConnectionEvent {
    public:
        BeforeNodesConnectedEvent(FlowEditor* editor, NodePin* sourceNodePin, NodePin* destinationNodePin)
            : BaseBeforeEvent(editor), NodesConnectionEvent(sourceNodePin, destinationNodePin) {}
    };

    class NodeConnectedEvent : public BaseEvent, public NodesConnectionEvent {
    public:
        NodeConnectedEvent(FlowEditor* editor, NodePin* sourceNodePin, NodePin* destinationNodePin)
            : BaseEvent(editor), NodesConnectionEvent(sourceNodePin, destinationNodePin) {}
    };
};

class FlowEditor : public sfl::Observable<FlowEditorEvents::NodeSelectedEvent*>,
        sfl::Observable<FlowEditorEvents::BeforeNodesConnectedEvent*>,
        sfl::Observable<FlowEditorEvents::NodeConnectedEvent*>
{
public:
    virtual ~FlowEditor() {}
    virtual FlowEditorNodeItem* createNodeItem(Node* node) = 0;
    virtual void deleteNodeItem(Node* node) = 0;
protected:
    void notifyOnNodeItemSelected(FlowEditorNodeItem* nodeItem) {
        FlowEditorEvents::NodeSelectedEvent event(this, nodeItem->getNode());
        sfl::Observable<FlowEditorEvents::NodeSelectedEvent*>::notifyObservers(&event);
    }
    void notifyBeforeNodeItemsConnected() {
        //FlowEditorBeforeNodeItemsConnectedEvent event(this, nodeItem->getNode());
        //sfl::Observable<FlowEditorNodeItemSelectedEvent>::notifyObservers(event);
    }
    void notifyOnNodeItemsConnected() {}
    void notifyBeforeNodeItemDeleted() {}
    void notifyOnNodeItemDeleted() {}
};

}

}
