#pragma once

#include "wfc_grid.h"
#include "vector_slot.h"

template <size_t N, size_t M>
class SquareGrid : public IWFCGrid {
    VectorSlot *grid[N * M];

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
        std::vector<std::shared_ptr<ISlot>> getValues() override;
        std::vector<int> getKeys() override;

};