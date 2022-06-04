#pragma once

#include "wfc_heuristic.h"
#include "wfc_grid.h"


class WFCSolver {

    WFCGrid *grid;
    WFCHeuristic *heuristic;

    public:
        WFCSolver(WFCGrid *grid, WFCHeuristic *heuristic) {
            this->grid = grid;
            this->heuristic = heuristic;
        }

        ~WFCSolver() {
            // delete this->grid;
            // delete this->heuristic;
        }

        virtual WFCGrid *run() = 0;

    protected:
        virtual void iterate() = 0;
        virtual void propagate() = 0;

};