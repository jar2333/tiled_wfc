#include "NeighborTileMap.h"

//Sets the tiles in the neighbor superposition to be valid or invalid based on this map
//returns a bool indicating if this caused the neighbor superposition to create a contradiction
bool NeighborTileMap::constrainNeighbor(ISuperposition& neighbor) {

    auto it = neighbor.getIterator();
    while (it->hasNext()) {
        TileKeyT key = it->getNext();
        if (!aggregate_valid_neighbor_tiles.count(key))
            neighbor.remove(key);
    }

    return neighbor.hasNone();
}

//Remove from this map all the potential neighbors of now unavailable tiles
void NeighborTileMap::update(ISuperposition& current) {
    std::unordered_set<TileKeyT> available;

    //Gets all TileKeys available in the current superposition
    auto it = current.getIterator();
    while (it->hasNext()) {
        TileKeyT key = it->getNext();
        available.insert(key);
    }
    
    //Remove from neighbor map all unavailable TileKeys
    for (auto it = valid_neighbor_tiles.begin(); it != valid_neighbor_tiles.end(); it++) {
        auto& pair = *it;
        TileKeyT v = pair.first;
        if (!available.count(v)) {
            valid_neighbor_tiles.removeNode(v);
        }
    }

    //aggregate maps to form aggregate neighbor tile set
    aggregate();
}

//a set union of all neighbor sets in the digraph valid_neighbor_tiles
//it yields aggregate_valid_neighbor_tiles, the set of allowed tiles for the neighbor!
void NeighborTileMap::aggregate() {
    aggregate_valid_neighbor_tiles.clear();

    for (auto it = valid_neighbor_tiles.begin(); it != valid_neighbor_tiles.end(); it++) {
        auto& pair = *it;
        auto& neighbors = pair.second;
        
        for (auto n : neighbors) {
            aggregate_valid_neighbor_tiles.insert(n.first);
        }
        
    }

}