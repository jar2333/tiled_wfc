#pragma once

#include "ITileSet.h"

class IGridSlot;

class INeighborMap {
  public:
    virtual bool constrainNeighbor(IGridSlot& neighbor_slot) = 0;
    virtual void update(IGridSlot& source_slot) = 0;
};