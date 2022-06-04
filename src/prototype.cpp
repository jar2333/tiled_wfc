#include "prototype.h"

Prototype::Prototype(std::string mesh_path, int rotation, std::string *h_sockets, std::string *v_sockets)
{
    this->mesh_path = mesh_path;
    this->rotation  = rotation;

    for (int i = 0; i < 4; i++)
        this->sockets[i] = h_sockets[i];

    for (int i = 0; i < 2; i++)
        this->sockets[4+i] = v_sockets[i];
}