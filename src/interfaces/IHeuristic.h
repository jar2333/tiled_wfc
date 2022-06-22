#pragma once 

#include "Key.h"

class IGrid;

class IHeuristic {
    public:
        virtual SuperpositionKeyT getNext(IGrid& grid) = 0;
};