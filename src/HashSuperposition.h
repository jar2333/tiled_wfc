#include "interfaces/ISuperposition.h"

#include <unordered_map>

class HashSuperposition : public ISuperposition {
        std::unordered_map<TileKeyT, double> tiles;
        size_t ones_count;

        //change to lazy initialization on getWeight if this is too slow
        void normalizeWeights(double removed_weight);

    public:
        HashSuperposition(std::unordered_map<TileKeyT, double> tiles) : tiles(tiles), ones_count(tiles.size()){}

        void remove(TileKeyT key) override;
        bool contains(TileKeyT key) const override;
        double getWeight(TileKeyT key) const override;
        bool hasNone() override;
        bool hasOne() override;
        size_t getOnesCount() override;

        std::unique_ptr<ISuperpositionIterator> getIterator() override; 

    private:

        class HashSuperpositionIterator : public ISuperpositionIterator {
            private:
                std::unordered_map<TileKeyT, double>::iterator it;
                std::unordered_map<TileKeyT, double>::iterator end;
            public:
                HashSuperpositionIterator(std::unordered_map<TileKeyT, double>& tiles);

                TileKeyT getNext();

                bool hasNext();
        };

};