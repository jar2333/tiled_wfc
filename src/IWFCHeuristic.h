#pragma once 

class IWFCGrid;

class IWFCHeuristic {
    public:
        virtual int getNext(IWFCGrid& grid) = 0;
};