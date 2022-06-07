#include "VectorNeighborSet.h"
#include "IGridSlot.h"

VectorNeighborSet::VectorNeighborSet(size_t size) {
    this->vector.reserve(size);
    for (size_t i = 0; i < size; i++)
        this->vector.push_back(true);
}

void VectorNeighborSet::set(size_t pos, bool val) {
    vector[pos] = val;
}

bool VectorNeighborSet::get(size_t pos) {
    return vector[pos];
}

bool VectorNeighborSet::constrainNeighbor(IGridSlot& neighbor_grid) {

    for (size_t i = 0; i < vector.size(); i++) {
        if (!get(i) && neighbor_grid.get(i))
            neighbor_grid.set(i, false);
    }

    return neighbor_grid.hasNone(); //return if, at the end, made a contradiction.
}