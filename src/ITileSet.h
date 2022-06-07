#pragma once

//needs an iterator
template<typename KeyT>
class ITileSet {
  public:
    virtual void set(KeyT pos, bool val) = 0;
    virtual bool get(KeyT pos) = 0;
};