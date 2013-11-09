#pragma once

#include <string>

#include <Node.h>

class FlowEditorNodeItem
{
private:
    Node* node;
public:
    FlowEditorNodeItem(Node* node) { this->node = node; }
    virtual ~FlowEditorNodeItem() {}
    Node* getNode() { return node; }
    virtual void addInputPin(const std::string& name) = 0;
    virtual void addOutputPin(const std::string& name) = 0;
};
