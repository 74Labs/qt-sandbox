#pragma once

#include <string>
#include <vector>

class Node
{
public:
    virtual ~Node() {}
    virtual const std::string getName() = 0;
    virtual const std::vector<std::string> getInputPins() = 0;
    virtual const std::vector<std::string> getOutputPins() = 0;
};

class MockNode: public Node
{
private:
    const std::string nodeName;
    std::vector<std::string> inputs;
    std::vector<std::string> outputs;
public:
    MockNode(const std::string& name):nodeName(name) {}
    const std::string getName() { return nodeName; }
    const std::vector<std::string> getInputPins() { return inputs; }
    const std::vector<std::string> getOutputPins() { return outputs; }
};
