#pragma once

#include <string>
#include <vector>

#include <sfl/Observable.h>

namespace sfl {

namespace flow {

class Node;
class NodePin;

class NodeEvents {

private:

    class BaseEvent {
    public:
        Node* node;
    public:
        BaseEvent(Node* node) : node(node) {}
    };

    class BasePinEvent {
    public:
        NodePin* pin;
    public:
        BasePinEvent(NodePin* pin) : pin(pin) {}
    };

public:

    class NodeDeletedEvent : public BaseEvent {};

    class PinAddedEvent : public BaseEvent, public BasePinEvent {
    public:
        PinAddedEvent(Node* node, NodePin* pin) : BaseEvent(node), BasePinEvent(pin) {}
    };

    class PinDeletedEvent : public BaseEvent, public BasePinEvent {
    public:
        PinDeletedEvent(Node* node, NodePin* pin) : BaseEvent(node), BasePinEvent(pin) {}
    };

};

class Node : public sfl::Observable<NodeEvents::PinAddedEvent*>, public sfl::Observable<NodeEvents::PinDeletedEvent*>
{
public:

private:
    const std::string nodeName;
    std::vector<NodePin*> nodeInputPins;
    std::vector<NodePin*> nodeOutputPins;
public:
    Node(const std::string& name) : nodeName(name) {}
    ~Node();
    const std::string getNodeName() { return nodeName; }
    const std::vector<NodePin*> getNodeInputPins() { return nodeInputPins; }
    const std::vector<NodePin*> getNodeOutputPins() { return nodeOutputPins; }
    Node* addNodeInputPin(const std::string& name, const std::string& protocolName = 0);
    Node* addNodeOutputPin(const std::string& name, const std::string& protocolName = 0);
};

class NodePin
{
public:
    enum Direction { Input = 1, Output = 2 };
private:
    const std::string pinName;
    const std::string pinProtocolName;
    Direction direction;
protected:

public:
    NodePin(const std::string& name, Direction direction, const std::string& protocolName = 0)
        : pinName(name), pinProtocolName(protocolName), direction(direction) {}
    ~NodePin();
    const std::string getPinName() { return pinName; }
    bool isPinMulti() { return true; }
    Direction getDirection() { return direction; }
    const std::string getPinProtocolName() { return pinProtocolName; }
};

}

}
