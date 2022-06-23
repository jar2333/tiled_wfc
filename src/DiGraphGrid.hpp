#include "interfaces/IGrid.hpp"
#include "interfaces/Key.hpp"

#include "DiGraph.hpp"
#include "NeighborTileMap.hpp"

#include <unordered_map>
#include <memory>

class DiGraphGridIterator : public IGridIterator {


};

class DiGraphGridNeighborIterator : public IGridNeighborIterator {


};

class DiGraphGrid : public IGrid {

    DiGraph<SuperpositionKeyT, NeighborTileMap> available_neighbor_tile_map;
    std::map<SuperpositionKeyT, std::shared_ptr<ISuperposition>> superpositions;

    public:
        DiGraphGrid() {

        }

        virtual void collapse(IHeuristic& h, ICollapseBehavior& cb) override;
        virtual void collapse(SuperpositionKeyT key, ICollapseBehavior& cb) override;
        virtual bool constrain(SuperpositionKeyT current_key, SuperpositionKeyT neighbor_key) override;
        virtual bool isCollapsed() override;
        virtual bool isContradiction() override;

        virtual std::shared_ptr<ISuperposition> getValue(SuperpositionKeyT key) override;

        virtual std::unique_ptr<IGridIterator> getIterator() override;
        virtual std::unique_ptr<IGridNeighborIterator> getNeighborIterator() override;

    private:

        class DiGraphGridIterator : public IGridIterator {


        };

        class DiGraphGridNeighborIterator : public IGridNeighborIterator {

            
        };

};