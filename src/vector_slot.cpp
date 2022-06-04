#include "vector_slot.h"

VectorSlot::VectorSlot(std::vector<bool>& v) {
    this->vector = v; //COPIES
}

void VectorSlot::set(size_t pos, bool val) {
    vector[pos] = val;
}

bool VectorSlot::get(size_t pos) {
    return vector[pos];
}

bool VectorSlot::any() {
    size_t s = this->vector.size();
    for (size_t i = 0; i < s; i++) {
        if (this->vector[i])
            return true;
    }
    return false;
}

bool VectorSlot::none() {
    return !any();
}