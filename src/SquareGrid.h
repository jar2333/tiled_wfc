#pragma once

#include "IWFCGrid.h"
#include "VectorSuperposition.h"
#include "VectorNeighborMap.h"

#include <map>

class SquareGrid : public IWFCGrid {
    size_t N, M;
    std::vector<std::shared_ptr<VectorSuperposition>> grid;
    std::vector<std::map<int, VectorNeighborMap>> neighbor_superpositions;

    public:
        SquareGrid(size_t N, size_t M, size_t superposition_size);
        ~SquareGrid();
        void collapse(IWFCHeuristic& h, ICollapseBehavior& cb) override;
        void collapse(int key, ICollapseBehavior& cb) override;
        bool constrain(int current_key, int neighbor_key) override;
        bool isCollapsed() override;
        bool isContradiction() override;
        std::vector<int> getNeighbors(int key) override;
        std::shared_ptr<IGridSuperposition> getValue(int key) override;
        std::vector<int> getKeys() override;

};