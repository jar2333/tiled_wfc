#pragma once

#include "INeighborMap.h"
#include <vector>
#include <map>

//an aggregate, should contain some mapping from IGridSlot pos (size_t) to a bool vector (hence namesake)
class VectorNeighborMap : public INeighborMap {

    std::map<size_t, std::vector<bool>> adjacencies;
    
    std::vector<bool> aggregate_vector;

    public:
        VectorNeighborMap(size_t size);
        bool constrainNeighbor(IGridSlot& neighbor_slot) override;
        void update(IGridSlot& source_slot) override;

    private:
        void set(size_t pos, bool val);
        bool get(size_t pos);
        void aggregate();

};