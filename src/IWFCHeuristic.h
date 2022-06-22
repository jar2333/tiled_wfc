#pragma once 

#include "Key.h"

class IWFCGrid;

class IWFCHeuristic {
    public:
        virtual SuperpositionKeyT getNext(IWFCGrid& grid) = 0;
};