#pragma once

#include "interfaces/IHeuristic.hpp"
#include "interfaces/IGrid.hpp"


class WFCSolver {

    IGrid& grid;
    IHeuristic& heuristic;

    public:
        WFCSolver(IGrid& grid, IHeuristic& heuristic) : grid(grid), heuristic(heuristic) {}

        virtual IGrid& run() = 0;

    protected:
        virtual void iterate() = 0;
        virtual void propagate() = 0;

};