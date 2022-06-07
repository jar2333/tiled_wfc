#pragma once

//needs an iterator
template<typename T>
class ITileSet {
  public:
    virtual void set(T pos, bool val) = 0;
    virtual bool get(T pos) = 0;
};