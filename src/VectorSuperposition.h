#pragma once

#include "IGridSuperposition.h"
#include <vector>

class VectorSuperposition : public IGridSuperposition {

    size_t ones_count;
    std::vector<bool> vector;

    public:
        VectorSuperposition() = default;
        VectorSuperposition(size_t size);
        void set(size_t pos, bool val) override;
        bool get(size_t pos) const override;
        bool hasNone() override;
        bool hasOne() override;
        size_t getOnesCount() override;

};