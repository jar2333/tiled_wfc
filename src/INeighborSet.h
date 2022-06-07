#pragma once

#include "ITileSet.h"

class IGridSlot;

class INeighborSet : ITileSet<size_t> {
  public:
    virtual bool constrainNeighbor(IGridSlot& neighbor_slot) = 0;
};