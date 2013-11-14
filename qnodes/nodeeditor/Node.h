#pragma once

#include <string>
#include <vector>

class NodePin;

class Node
{
private:
    const std::string nodeName;
    std::vector<NodePin*> nodeInputPins;
    std::vector<NodePin*> nodeOutputPins;
public:
    Node(const std::string& name);
    ~Node();
    const std::string getNodeName() { return nodeName; }
    const std::vector<NodePin*> getNodeInputPins() { return nodeInputPins; }
    const std::vector<NodePin*> getNodeOutputPins() { return nodeOutputPins; }
    NodePin* addNodeInputPin(const std::string& name, const std::string& protocolName = 0);
    NodePin* addNodeOutputPin(const std::string& name, const std::string& protocolName = 0);
};

class NodePin
{
private:
    const std::string pinName;
    const std::string pinProtocolName;
protected:

public:
    NodePin(const std::string& name, const std::string& protocolName = 0);
    ~NodePin();
    const std::string getPinName() { return pinName; }
    bool isPinMulti() { return true; }
    const std::string getPinProtocolName() { return pinProtocolName; }
};
