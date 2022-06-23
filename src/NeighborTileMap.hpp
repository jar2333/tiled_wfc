#pragma once

#include "DiGraph.hpp"
#include "interfaces/Key.hpp"
#include "interfaces/ISuperposition.hpp"

#include <unordered_set>

class NeighborTileMap {

    private:
        DiGraph<TileKeyT, bool> valid_neighbor_tiles;
        std::unordered_set<TileKeyT> aggregate_valid_neighbor_tiles;

        void aggregate();

    public:
        NeighborTileMap(DiGraph<TileKeyT, bool> g): valid_neighbor_tiles(g) {
            aggregate();
        }

        bool constrainNeighbor(ISuperposition& neighbor); 

        void update(ISuperposition& current);

};