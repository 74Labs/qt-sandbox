#pragma once

class Node
{
public:
    virtual ~Node() {}
    virtual std::string getName() = 0;
    virtual std::vector<std::string> getInputNodes() = 0;
    virtual sts::vector<std::string> getOutputNodes() = 0;
};
