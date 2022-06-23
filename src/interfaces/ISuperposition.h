#pragma once

#include "Key.h"
#include <memory>

class ISuperpositionIterator {
  public:
    virtual TileKeyT getNext()= 0;
    virtual bool hasNext() = 0;
};

//All superpositions are weighted, weights add up to 1!
class ISuperposition {
  public:
    virtual void remove(TileKeyT key) = 0;
    virtual bool contains(TileKeyT key) const = 0;
    virtual double getWeight(TileKeyT key) const = 0;
    virtual bool hasNone() = 0;
    virtual bool hasOne() = 0;
    virtual size_t getOnesCount() = 0;

    virtual std::unique_ptr<ISuperpositionIterator> getIterator() = 0; 
};