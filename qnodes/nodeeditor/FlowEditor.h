#pragma once

#include <Node.h>
#include <NodeType.h>

#include <FlowEditorNodeItem.h>

class FlowEditor
{
public:
    virtual ~FlowEditor() {}
    virtual void addNodeItem(Node* node) = 0;
    virtual void deleteNodeItem(Node* node) = 0;

    //virtual std::vector<FlowEditorNodeItem*> getItems() = 0;
/*
    virtual void addNodeItem(const std::string& name, std::vector<std::string>& inputPins, std::vector<std::string>& outputPins) = 0;
    virtual void addNodeItem(const std::string& name, std::string inputPins[], unsigned int inputPinsCount, std::string outputPins[], unsigned int outputPortsCount) = 0;
    virtual void addNodeItem(const std::string& name, unsigned int inputPins, unsigned int outputPins) = 0;
    virtual void addNodeItem(const std::string& name, NodePinList& inputPins, NodePinList& outputPins) = 0;
*/
protected:
    //virtual void connectNodePins(NodePin* sourcePin, NodePin* destinationPin) = 0;
};
