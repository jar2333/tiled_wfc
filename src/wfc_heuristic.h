#pragma once 

class WFCGrid;

class WFCHeuristic {
    public:
        virtual int getNext(WFCGrid& grid) = 0;
};