#pragma once

#include <vector>
#include <string>

class NodePinList: public std::vector<std::string>
{
public:
   // NodePinList(std::string names[], unsigned int size);
    NodePinList(const char* names[], unsigned int size);
};
