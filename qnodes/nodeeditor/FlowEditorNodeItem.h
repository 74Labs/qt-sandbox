#pragma once

#include <string>

#include <Node.h>

namespace sfl {

namespace flow {

class FlowEditorNodeItemPin;

class FlowEditorNodeItem {
private:
    Node* node;
public:
    FlowEditorNodeItem(Node* node) : node(node) {}
    virtual ~FlowEditorNodeItem() {}
    Node* getNode() { return node; }
    virtual void setPosition(float x, float y) = 0;
    virtual FlowEditorNodeItemPin* addPin(NodePin* pin) = 0;
    //virtual void deleteInputPin(const std::string& name) = 0;
};

class FlowEditorNodeItemPin {
private:
    NodePin* pin;
public:
    FlowEditorNodeItemPin(NodePin* pin) : pin(pin) {}
    virtual ~FlowEditorNodeItemPin() {}
    NodePin* getPin() { return pin; }
};

}

}
