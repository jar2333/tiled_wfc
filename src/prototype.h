#pragma once 

#include <string>

class Prototype
{
    std::string mesh_path;
    int rotation;
    std::string sockets[6];

public:
    Prototype(std::string mesh_path, int rotation, std::string *h_sockets, std::string *v_sockets);

    std::string getFront();
    std::string getRight();
    std::string getBack();
    std::string getLeft();
    std::string getTop();
    std::string getBottom();

};