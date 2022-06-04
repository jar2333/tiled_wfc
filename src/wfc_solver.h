#pragma once

#include "wfc_heuristic.h"
#include "wfc_grid.h"


class WFCSolver {

    WFCGrid& grid;
    WFCHeuristic& heuristic;

    public:
        WFCSolver(WFCGrid& grid, WFCHeuristic& heuristic) : grid(grid), heuristic(heuristic) {}

        virtual WFCGrid& run() = 0;

    protected:
        virtual void iterate() = 0;
        virtual void propagate() = 0;

};