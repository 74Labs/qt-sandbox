#pragma once



class NodeType
{
public:
    struct PinDefinition
    {
        enum Direction { In = 0, Out = 1};
        std::string name;
        Direction direction;
        bool multi;
    };
private:
    std::string name;
    std::vector<PinDefinition> pins;
public:
    std::string& getName() { return name; }
    std::vector<PinDefinition> getInputPins() { return pins; }
};
