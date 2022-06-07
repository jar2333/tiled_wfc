#pragma once

#include "IWFCHeuristic.h"
#include "IWFCGrid.h"


class WFCSolver {

    IWFCGrid& grid;
    IWFCHeuristic& heuristic;

    public:
        WFCSolver(IWFCGrid& grid, IWFCHeuristic& heuristic) : grid(grid), heuristic(heuristic) {}

        virtual IWFCGrid& run() = 0;

    protected:
        virtual void iterate() = 0;
        virtual void propagate() = 0;

};