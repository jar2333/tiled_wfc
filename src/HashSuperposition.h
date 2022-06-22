#include "interfaces/ISuperposition.h"

#include <unordered_map>

class HashSuperposition : public ISuperposition {
    private:
        std::unordered_map<TileKeyT, double> tiles;
        size_t ones_count;

        class HashSuperpositionIterator : public ISuperpositionIterator {
            private:
                std::unordered_map<TileKeyT, double>::iterator it;
                std::unordered_map<TileKeyT, double>::iterator end;
            public:
                HashSuperpositionIterator(std::unordered_map<TileKeyT, double>& tiles) {
                    it = tiles.begin();
                    end = tiles.end();
                }

                TileKeyT getNext() {
                    auto next = *(it++);
                    return next.first;
                }

                bool hasNext() {
                    return it != end;
                }
        };

        void normalizeWeights(double removed_weight);

    public:
        HashSuperposition(std::unordered_map<TileKeyT, double> tiles) : tiles(tiles), ones_count(tiles.size()) {}

        void set(TileKeyT key, bool val) override;
        bool get(TileKeyT key) const override;
        double getWeight(TileKeyT key) const override;
        bool hasNone() override;
        bool hasOne() override;
        size_t getOnesCount() override;

        std::unique_ptr<ISuperpositionIterator> getIterator() override; 

};