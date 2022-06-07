#pragma once

#include "wfc_grid.h"
#include "vector_slot.h"

class SquareGrid : public IWFCGrid {
    std::vector<std::shared_ptr<VectorSlot>> grid;

    public:
        SquareGrid(size_t slot_size);
        ~SquareGrid();
        void collapse(IWFCHeuristic& h) override;
        void collapse(int key, ICollapseBehavior& cb) override;
        bool constrain(int current, int neighbor) override;
        bool isCollapsed() override;
        bool isContradiction() override;
        std::vector<int> getNeighbors() override;
        std::shared_ptr<ISlot> getValue(int key) override;
        std::vector<int> getKeys() override;

};