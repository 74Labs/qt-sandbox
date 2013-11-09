#include <NodePinList.h>

/*
NodePinList::NodePinList(std::string names[], unsigned int size):std::vector<std::string>(size)
{
    for(unsigned int i = 0; i < size; i++)
        push_back(names[i]);
}
*/

NodePinList::NodePinList(const char* names[], unsigned int size):std::vector<std::string>(size)
{
    for(unsigned int i = 0; i < size; i++)
        push_back(names[i]);
}
