#pragma once

#include "Key.h"

class IGridSuperposition {
  public:
    virtual void set(TileKeyT key, bool val) = 0;
    virtual bool get(TileKeyT key) const = 0;
    virtual bool hasNone() = 0;
    virtual bool hasOne() = 0;
    virtual size_t getOnesCount() = 0;
};