#include <Node.h>

#include <iostream>

Node::Node(const std::string &name) : nodeName(name)
{

}

Node::~Node()
{
    while(!nodeInputPins.empty()) delete nodeInputPins.back(), nodeInputPins.pop_back();
    while(!nodeOutputPins.empty()) delete nodeOutputPins.back(), nodeOutputPins.pop_back();
    std::cout << "Node destroyed" << std::endl;
}

NodePin *Node::addNodeInputPin(const std::string &name, const std::string &protocolName)
{
    NodePin* node = new NodePin(name, protocolName);
    nodeInputPins.push_back(node);
    return node;
}

NodePin *Node::addNodeOutputPin(const std::string &name, const std::string &protocolName)
{
    NodePin* node = new NodePin(name, protocolName);
    nodeOutputPins.push_back(node);
    return node;
}

NodePin::NodePin(const std::string &name, const std::string &protocolName)  : pinName(name), pinProtocolName(protocolName)
{

}

NodePin::~NodePin()
{
    std::cout << "Node Pin destroyed" << std::endl;
}
