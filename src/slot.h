#pragma once

class Slot {
  public:
    virtual void set(size_t pos, bool val) = 0;
    virtual bool get(size_t pos) = 0;
    virtual bool any() = 0;
    virtual bool none() = 0;
};