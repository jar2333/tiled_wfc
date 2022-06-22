#include "HashSuperposition.h"

void HashSuperposition::set(TileKeyT key, bool val) {
    if (!val) {
        double weight = tiles.at(key);
        tiles.erase(key);
        ones_count--;
        normalizeWeights(weight);
    }
}

bool HashSuperposition::get(TileKeyT key) const {
    return tiles.count(key);
}
double HashSuperposition::getWeight(TileKeyT key) const {
    return tiles.at(key);
}
bool HashSuperposition::hasNone() {
    return ones_count <= 0;
}
bool HashSuperposition::hasOne() {
    return ones_count == 1;
}
size_t HashSuperposition::getOnesCount() {
    return ones_count;
}

std::unique_ptr<ISuperpositionIterator> HashSuperposition::getIterator() {
    std::unique_ptr<ISuperpositionIterator> it(new HashSuperpositionIterator(tiles));
    return it;
}

//good enough, i think...
void HashSuperposition::normalizeWeights(double removed_weight) {
    double unnormalized_total_weight = 1 - removed_weight;
    for (auto pair : tiles) {
        pair.second /= unnormalized_total_weight;
    }
}