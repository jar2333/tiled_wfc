#pragma once

class IGridSuperposition;

class INeighborMap {
  public:
    virtual bool constrainNeighbor(IGridSuperposition& neighbor_slot) = 0;
    virtual void update(const IGridSuperposition& source_slot) = 0;
};