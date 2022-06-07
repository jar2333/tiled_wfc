#include "VectorNeighborSet.h"

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

    return true;
}