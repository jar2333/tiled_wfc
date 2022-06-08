#include "VectorNeighborMap.h"
#include "IGridSlot.h"

VectorNeighborMap::VectorNeighborMap(std::map<size_t, std::vector<bool>> adj, size_t slot_size) {
    this->aggregate_vector.reserve(slot_size);
    this->slot_size = slot_size;
    this->aggregate();
}

bool VectorNeighborMap::constrainNeighbor(IGridSlot& neighbor_grid) {
    //lazy evaluation
    if (!is_aggregated) {
        aggregate();
    }
    for (size_t i = 0; i < slot_size; i++) {
        if (!get(i) && neighbor_grid.get(i))
            neighbor_grid.set(i, false);
    }

    return neighbor_grid.hasNone(); //return if, at the end, made a contradiction.
}

void VectorNeighborMap::update(const IGridSlot& source_slot) {
    for (size_t i = 0; i < slot_size; i++) {
        if (!source_slot.get(i)) { //no longer in slot
            adjacencies.erase(i);
            is_aggregated = false;
        }
    }
}

//The bitwise or, set union
void VectorNeighborMap::aggregate() {
    for (auto const& x : adjacencies) {
        auto& vec = x.second;
        for (size_t i = 0; i < slot_size; i++) 
            aggregate_vector[i] = aggregate_vector[i] || vec[i];
    }
}

bool VectorNeighborMap::get(size_t i) {
    return aggregate_vector[i];
}