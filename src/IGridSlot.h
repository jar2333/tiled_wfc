#pragma once

#include "ITileSet.h"

class IGridSlot : ITileSet<size_t> {
  public:
    virtual bool hasNone() = 0;
    virtual bool hasOne() = 0;
    virtual size_t getOnesCount() = 0;
};