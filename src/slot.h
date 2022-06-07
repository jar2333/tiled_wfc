#pragma once

#include "tile_set.h"

class IGridSlot : ITileSet<size_t> {
  public:
    virtual bool any() = 0;
    virtual bool none() = 0;
    virtual size_t ones() = 0;
};