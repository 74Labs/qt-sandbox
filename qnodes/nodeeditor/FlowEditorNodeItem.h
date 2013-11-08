#pragma once

#include <string>

class FlowEditorNodeItem
{
public:
    virtual ~FlowEditorNodeItem() {}
    virtual void addInputPin(const std::string& name) = 0;
    virtual void addOutputPin(const std::string& name) = 0;
};
