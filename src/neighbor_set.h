#pragma once

#include "tile_set.h"

class IGridSlot;

class INeighborSet : ITileSet<size_t> {
  public:
    virtual bool constrain(IGridSlot& slot) = 0;
};