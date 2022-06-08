#pragma once

class IGridSlot;

class INeighborMap {
  public:
    virtual bool constrainNeighbor(IGridSlot& neighbor_slot) = 0;
    virtual void update(const IGridSlot& source_slot) = 0;
};