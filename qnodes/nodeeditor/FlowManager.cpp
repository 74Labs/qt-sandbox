#include <FlowManager.h>

#include <exception>
#include <iostream>
#include <sfl/Debug.h>

namespace sfl {

namespace flow {

FlowManager::~FlowManager()
{
    for(NodeItemMapIterator i = nodes.begin(); i != nodes.end(); ++i) {
        unregisterNodeObserver(i->first);
        if(nodesOwner) delete i->first;
    }
}

NodeType *FlowManager::addNodeTemplate(const std::string &name)
{
    NodeType* nodeTemplate = new NodeType();
    nodeTemplates.insert(NodeTemplateMap::value_type(name, nodeTemplate));
    return nodeTemplate;
}

Node *FlowManager::createNode(const std::string &name)
{
    Node* node = new Node(name);
    addNode(node);
    return node;
}

void FlowManager::addNode(Node *node)
{
    nodes.insert(NodeItemMap::value_type(node, editor->createNodeItem(node)));
    registerAsNodeObserver(node);
}

void FlowManager::notify(FlowEditorEvents::NodeSelectedEvent *event)
{
    //DEBUG_COUT(event->node->getNodeName() << " selected");
}

void FlowManager::notify(NodeEvents::PinAddedEvent *event)
{
    NodeItemMapIterator i = nodes.find(event->node);
    FlowEditorNodeItem* nodeItem = i->second;
    if(!nodeItem) throw std::exception();
    nodeItem->addPin(event->pin);
    DEBUG_COUT(event->node->getNodeName() << ":" << event->pin->getPinName() << " pin added");
}

void FlowManager::notify(NodeEvents::PinDeletedEvent *event)
{
    DEBUG_COUT(event->node->getNodeName() << ":" << event->pin->getPinName() << " pin deleted");
}

void FlowManager::registerAsNodeObserver(Node *node)
{
    node->Observable<NodeEvents::PinAddedEvent*>::registerObserver(this);
    node->Observable<NodeEvents::PinDeletedEvent*>::registerObserver(this);
}

void FlowManager::unregisterNodeObserver(Node *node)
{
    node->Observable<NodeEvents::PinAddedEvent*>::unregisterObserver(this);
    node->Observable<NodeEvents::PinDeletedEvent*>::unregisterObserver(this);
}

/*
    NodeTemplateMapIterator i = nodeTemplates.find(templateName);

    NodeType* nodeTemplate = i->second;
    if(!nodeTemplate) throw std::exception();
    Node* node = new MockNode(node);
    for(std::vector<std::string>::iterator i = nodeTemplate->getInputPins().begin(); i != nodeTemplate->getInputPins().end(); ++i) {
        node->getInputPins().push_back(i->name);
    }
    editor->addNodeItem(node);
    return node;
}
*/

}

}
