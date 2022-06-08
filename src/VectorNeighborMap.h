#pragma once

#include "INeighborMap.h"
#include <vector>
#include <map>

//an aggregate, should contain some mapping from 
//IGridSuperposition pos (size_t) to a bool vector (hence namesake)
class VectorNeighborMap : public INeighborMap {

    size_t slot_size;
    std::map<size_t, std::vector<bool>> adjacencies;
    std::vector<bool> aggregate_vector; //lazily evaluated
    bool is_aggregated = true;


    public:
        VectorNeighborMap(std::map<size_t, std::vector<bool>> adj, size_t slot_size);
        bool constrainNeighbor(IGridSuperposition& neighbor_slot) override;
        void update(const IGridSuperposition& source_slot) override;

    private:
        void aggregate();
        bool get(size_t i);

};