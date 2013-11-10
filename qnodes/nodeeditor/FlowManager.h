#pragma once

#include <map>
#include <string>

#include <FlowEditor.h>
#include <NodeType.h>
#include <Node.h>

class FlowManager
{
private:
    typedef std::map<std::string, NodeType*> NodeTemplateMap;
    typedef NodeTemplateMap::iterator NodeTemplateMapIterator;
    FlowEditor* editor;
    NodeTemplateMap nodeTemplates;
    std::vector<Node*> nodes;
public:
    FlowManager(FlowEditor* editor) { setEditor(editor); }

    NodeType* addNodeTemplate(const std::string& name);

    Node* addNode(const std::string& name, const std::string& templateName);

    void loadFlowFromFile(const std::string& filename);
    void saveFlowToFile(const std::string& filename);
    void loadNodeTypesFromFile(const std::string& filename);
    void saveNodeTypesToFile(const std::string& filename);

private:
    //void addNode(const std::string& name, NodeType* nodeTemplate);

public:
    void setEditor(FlowEditor* editor) { this->editor = editor; }
};
