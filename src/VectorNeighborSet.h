#pragma once

#include "INeighborSet.h"
#include <vector>

class VectorNeighborSet : public INeighborSet {

    std::vector<bool> vector;

    public:
        VectorNeighborSet(size_t size);
        void set(size_t pos, bool val) override;
        bool get(size_t pos) override;
        bool constrainNeighbor(IGridSlot& neighbor_slot) override;

};