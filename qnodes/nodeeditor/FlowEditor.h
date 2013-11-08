#pragma once

#include <string>
#include <vector>

class FlowEditor
{
public:
    virtual ~FlowEditor() {}
    virtual void addNodeItem(const std::string& name, std::vector<std::string>& inputPins, std::vector<std::string>& outputPins) = 0;
    virtual void addNodeItem(const std::string& name, std::string inputPins[], unsigned int inputPinsCount, std::string outputPins[], unsigned int outputPortsCount) = 0;
    virtual void addNodeItem(const std::string& name, unsigned int inputPins, unsigned int outputPins) = 0;
};
