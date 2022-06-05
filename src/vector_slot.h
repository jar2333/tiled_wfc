#pragma once

#include "slot.h"
#include <vector>

class VectorSlot : public Slot {

    size_t ones_count;
    std::vector<bool> vector;

    public:
        VectorSlot() = default;
        VectorSlot(size_t size);
        void set(size_t pos, bool val) override;
        bool get(size_t pos) override;
        bool any() override;
        bool none() override;
        size_t ones() override;

};