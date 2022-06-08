#pragma once

class IGridSuperposition;

class INeighborMap {
  public:
    virtual bool constrainNeighbor(IGridSuperposition& neighbor_superposition) = 0;
    virtual void update(const IGridSuperposition& source_superposition) = 0;
};