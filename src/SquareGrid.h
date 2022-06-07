#pragma once

#include "IWFCGrid.h"
#include "VectorSlot.h"

class SquareGrid : public IWFCGrid {
    size_t N, M;
    std::vector<std::shared_ptr<VectorSlot>> grid;

    public:
        SquareGrid(size_t N, size_t M, size_t slot_size);
        ~SquareGrid();
        void collapse(IWFCHeuristic& h, ICollapseBehavior& cb) override;
        void collapse(int key, ICollapseBehavior& cb) override;
        bool constrain(int current, int neighbor) override;
        bool isCollapsed() override;
        bool isContradiction() override;
        std::vector<int> getNeighbors() override;
        std::shared_ptr<IGridSlot> getValue(int key) override;
        std::vector<int> getKeys() override;

};