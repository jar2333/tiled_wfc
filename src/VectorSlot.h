#pragma once

#include "IGridSlot.h"
#include <vector>

class VectorSlot : public IGridSlot {

    size_t ones_count;
    std::vector<bool> vector;

    public:
        VectorSlot() = default;
        VectorSlot(size_t size);
        void set(size_t pos, bool val) override;
        bool get(size_t pos) const override;
        bool hasNone() override;
        bool hasOne() override;
        size_t getOnesCount() override;

};