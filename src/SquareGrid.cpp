#include "SquareGrid.h"
#include "IWFCHeuristic.h"
#include "ICollapseBehavior.h"

SquareGrid::SquareGrid(size_t N, size_t M, size_t slot_size) {
    this->N = N;
    this->M = M;
    size_t size = N*M;
    this->grid.reserve(size);
    for (size_t i = 0; i < size; i++) {
        auto ptr = std::make_shared<VectorSlot>(size);
        grid.push_back(ptr);
    }
}

SquareGrid::~SquareGrid() {}

void SquareGrid::collapse(IWFCHeuristic& h, ICollapseBehavior& cb) {
    int key = h.getNext(*this);
    this->collapse(key, cb);
}

void SquareGrid::collapse(int key, ICollapseBehavior& cb) {
    cb.collapse(*grid[key]);
}

// bool SquareGrid::constrain(int current, int neighbor) {
//     return true;
// }


//Can be made more efficient with a collapsed counter 
bool SquareGrid::isCollapsed() {
    for (size_t i = 0; i < grid.size(); i++) {
        if (!grid[i]->hasOne())
            return false;
    }
    return true;
}

//Can be made more efficient with a contradiction boolean
bool SquareGrid::isContradiction() {
    for (size_t i = 0; i < grid.size(); i++) {
        if (grid[i]->hasNone())
            return true;
    }
    return false;
}

std::vector<int> SquareGrid::getNeighbors(int key) {
    std::vector<int> neighbor_keys;
    neighbor_keys.reserve(4);

    int up_key    = key - N;
    int down_key  = key + N;
    int right_key = key + 1;
    int left_key  = key - 1;

    if (up_key < 0)
        neighbor_keys.push_back(up_key);
    if (down_key > N*M - 1)
        neighbor_keys.push_back(down_key);
    if (right_key % N == 0)
        neighbor_keys.push_back(right_key);
    if (left_key % N == N - 1)
        neighbor_keys.push_back(left_key);

    return neighbor_keys;
}

std::shared_ptr<IGridSlot> SquareGrid::getValue(int key) {
    return grid[key];
}

//slow and dumb, an iterator works with just a single counter variable
std::vector<int> SquareGrid::getKeys() {
    std::vector<int> keys;
    keys.reserve(grid.size());
    for (size_t i = 0; i < grid.size(); i++)
        keys.push_back(i);
    return keys;
}
