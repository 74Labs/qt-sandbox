#include <FlowManager.h>

#include <exception>

FlowManager::NodeType *FlowManager::addNodeTemplate(const std::string &name)
{
    NodeType* nodeTemplate = new NodeType();
    nodeTemplates.insert(nodeTemplates.value_type(name, nodeType));
    return nodeTemplate;
}

Node* FlowManager::addNode(const std::string& name, const std::string& templateName)
{
    NodeType* nodeTemplate = nodeTemplates.find(templateName);
    if(!nodeTemplate) throw std::exception("Template with given name not exists");
    Node* node = new Node(name);
    ppooppopo
    return node;
}
