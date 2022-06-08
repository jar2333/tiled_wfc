#include "VectorSuperposition.h"

VectorSuperposition::VectorSuperposition(size_t size) {
    this->vector.reserve(size);
    this->ones_count = size;
    for (size_t i = 0; i < size; i++)
        this->vector.push_back(true);
}

void VectorSuperposition::set(size_t pos, bool val) {
    bool current_val = vector[pos];
    if (!current_val && val) {
        this->ones_count++;
    } 
    else if (current_val && !val) {
        this->ones_count--;
    }
    vector[pos] = val;
}

bool VectorSuperposition::get(size_t pos) const {
    return vector[pos];
}

bool VectorSuperposition::hasNone() {
    return ones_count == 0;
}

bool VectorSuperposition::hasOne() {
    return ones_count == 1;
}

size_t VectorSuperposition::getOnesCount() {
    return ones_count;
}