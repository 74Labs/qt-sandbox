#include <FlowManager.h>

#include <exception>
#include <QXmlStreamReader>

NodeType *FlowManager::addNodeTemplate(const std::string &name)
{
    NodeType* nodeTemplate = new NodeType();
    nodeTemplates.insert(NodeTemplateMap::value_type(name, nodeTemplate));
    return nodeTemplate;
}

void FlowManager::addNode(Node *node)
{
    editor->addNodeItem(node);
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
