#include <Node.h>

#include <sfl/Debug.h>

namespace sfl {

namespace flow {



Node::~Node()
{
    while(!nodeInputPins.empty()) delete nodeInputPins.back(), nodeInputPins.pop_back();
    while(!nodeOutputPins.empty()) delete nodeOutputPins.back(), nodeOutputPins.pop_back();
    DEBUG_COUT("Node destroyed");
}

Node *Node::addNodeInputPin(const std::string &name, const std::string &protocolName)
{
    NodePin* pin = new NodePin(name, NodePin::Direction::Input, protocolName);
    nodeInputPins.push_back(pin);
    NodeEvents::PinAddedEvent event(this, pin);
    Observable<NodeEvents::PinAddedEvent*>::notifyObservers(&event);
    return this;
}

Node *Node::addNodeOutputPin(const std::string &name, const std::string &protocolName)
{
    NodePin* pin = new NodePin(name, NodePin::Direction::Output, protocolName);
    nodeOutputPins.push_back(pin);
    NodeEvents::PinAddedEvent event(this, pin);
    this->Observable<NodeEvents::PinAddedEvent*>::notifyObservers(&event);
    return this;
}

NodePin::~NodePin()
{
    DEBUG_COUT("Node Pin destroyed");
}

}

}
