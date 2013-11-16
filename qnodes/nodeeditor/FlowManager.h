#pragma once

#include <map>
#include <string>

#include <FlowEditor.h>
#include <NodeType.h>
#include <Node.h>

#include <sfl/Observer.h>

namespace sfl {

namespace flow {

class FlowManager : public sfl::Observer<FlowEditorEvents::NodeSelectedEvent*>,
        public sfl::Observer<NodeEvents::PinAddedEvent*>, public sfl::Observer<NodeEvents::PinDeletedEvent*>
{
private:

    typedef std::map<std::string, NodeType*> NodeTemplateMap;
    typedef NodeTemplateMap::iterator NodeTemplateMapIterator;
    typedef std::map<Node*, FlowEditorNodeItem*> NodeItemMap;
    typedef NodeItemMap::iterator NodeItemMapIterator;

    FlowEditor* editor;
    NodeTemplateMap nodeTemplates;
    NodeItemMap nodes;
    bool nodesOwner;

public:

    FlowManager(FlowEditor* editor, bool nodesOwner = false) : nodesOwner(nodesOwner) { setEditor(editor); }
    ~FlowManager();

    NodeType* addNodeTemplate(const std::string& name);

    Node* createNode(const std::string& name);
    void addNode(Node* node);

    void loadFlowFromFile(const std::string& filename);
    void saveFlowToFile(const std::string& filename);
    void loadNodeTypesFromFile(const std::string& filename);
    void saveNodeTypesToFile(const std::string& filename);

protected:

    void registerAsNodeObserver(Node* node);
    void unregisterNodeObserver(Node* node);
    void notify(FlowEditorEvents::NodeSelectedEvent* event);
    void notify(NodeEvents::PinAddedEvent* event);
    void notify(NodeEvents::PinDeletedEvent* event);

public:

    void setEditor(FlowEditor* editor) { this->editor = editor; editor->Observable<FlowEditorEvents::NodeSelectedEvent*>::registerObserver(this); }

};

}

}
