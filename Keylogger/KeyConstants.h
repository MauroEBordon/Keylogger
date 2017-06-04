#ifndef KEYCONSTANTS_H
#define KEYCONSTANTS_H

#include <map>    //Like an array except that every value has a key element como un ID.
#include <string>

class KeyPair
{
    public:
        KeyPair(const std::string &vk = "", const std::string &name = "") : VKName(vk), Name(name){} //This forms our KeyPair phases
        std::string VKName;
        std::string Name;
};


#endif // KEYCONSTANTS_H
