#include <FlowManager.h>

#include <exception>

NodeType *FlowManager::addNodeTemplate(const std::string &name)
{
    NodeType* nodeTemplate = new NodeType();
    nodeTemplates.insert(NodeTemplateMap::value_type(name, nodeTemplate));
    return nodeTemplate;
}

Node* FlowManager::addNode(const std::string& name, const std::string& templateName)
{
    NodeTemplateMapIterator i = nodeTemplates.find(templateName);

    NodeType* nodeTemplate = i->second;
    if(!nodeTemplate) throw std::exception();
    Node* node = new MockNode(name);
    return node;
}
