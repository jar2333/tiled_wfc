#pragma once

//needs an iterator
template<typename KeyT>
class ITileSet {
  public:
    virtual void set(KeyT key, bool val) = 0;
    virtual bool get(KeyT key) = 0;
};