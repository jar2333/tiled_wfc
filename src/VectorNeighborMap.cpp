#include "VectorNeighborMap.h"
#include "IGridSuperposition.h"

VectorNeighborMap::VectorNeighborMap(std::map<size_t, std::vector<bool>> adj, size_t superposition_size) {
    this->aggregate_vector.reserve(superposition_size);
    this->adjacencies = adj;
    this->superposition_size = superposition_size;
    this->aggregate();
}

bool VectorNeighborMap::constrainNeighbor(IGridSuperposition& neighbor_grid) {
    //lazy evaluation
    if (!is_aggregated) {
        aggregate();
    }
    for (size_t i = 0; i < superposition_size; i++) {
        if (!get(i) && neighbor_grid.get(i))
            neighbor_grid.set(i, false);
    }

    return neighbor_grid.hasNone(); //return if, at the end, made a contradiction.
}

void VectorNeighborMap::update(const IGridSuperposition& source_superposition) {
    for (size_t i = 0; i < superposition_size; i++) {
        if (!source_superposition.get(i)) { //no longer in superposition
            adjacencies.erase(i);
            is_aggregated = false;
        }
    }
}

//The bitwise or, set union
void VectorNeighborMap::aggregate() {
    for (auto const& x : adjacencies) {
        auto& vec = x.second;
        for (size_t i = 0; i < superposition_size; i++) 
            aggregate_vector[i] = aggregate_vector[i] || vec[i];
    }
}

bool VectorNeighborMap::get(size_t i) {
    return aggregate_vector[i];
}