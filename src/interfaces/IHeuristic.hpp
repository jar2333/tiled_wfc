#pragma once 

#include "Key.hpp"

class IGrid;

class IHeuristic {
    public:
        virtual SuperpositionKeyT getNext(IGrid& grid) = 0;
};