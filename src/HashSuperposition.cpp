#include "HashSuperposition.h"

void HashSuperposition::remove(TileKeyT key) {
    double weight = tiles.at(key);
    tiles.erase(key);
    ones_count--;
    normalizeWeights(weight); //perhaps use an interator parameter thing to only normalize at the end
}

bool HashSuperposition::contains(TileKeyT key) const {
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

HashSuperposition::HashSuperpositionIterator::HashSuperpositionIterator(std::unordered_map<TileKeyT, double>& tiles) : it(tiles.begin()), end(tiles.end()) {}

TileKeyT HashSuperposition::HashSuperpositionIterator::getNext() {
    auto next = *(it++);
    return next.first;
}

bool HashSuperposition::HashSuperpositionIterator::hasNext() {
    return it != end;
}