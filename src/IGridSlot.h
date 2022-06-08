#pragma once

class IGridSlot {
  public:
    virtual void set(size_t key, bool val) = 0;
    virtual bool get(size_t key) const = 0;
    virtual bool hasNone() = 0;
    virtual bool hasOne() = 0;
    virtual size_t getOnesCount() = 0;
};