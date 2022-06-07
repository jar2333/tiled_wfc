#include "vector_slot.h"

VectorSlot::VectorSlot(size_t size) {
    this->vector.reserve(size);
    this->ones_count = size;
    for (size_t i = 0; i < size; i++)
        this->vector.push_back(true);
}

void VectorSlot::set(size_t pos, bool val) {
    bool current_val = vector[pos];
    if (!current_val && val) {
        this->ones_count++;
    } 
    else if (current_val && !val) {
        this->ones_count--;
    }
    vector[pos] = val;
}

bool VectorSlot::get(size_t pos) {
    return vector[pos];
}

bool VectorSlot::hasNone() {
    return ones_count == 0;
}

bool VectorSlot::hasOne() {
    return ones_count == 1;
}
size_t VectorSlot::getOnesCount() {
    return ones_count;
}