#pragma once

#include "slot.h"
#include <vector>

class VectorSlot : public Slot {

    std::vector<bool> vector;

    public:
        VectorSlot() = default;
        VectorSlot(std::vector<bool>& v);
        void set(size_t pos, bool val);
        bool get(size_t pos);
        bool any();
        bool none();

};