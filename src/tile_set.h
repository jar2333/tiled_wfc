#pragma once

template<class T>
class ITileSet {
  public:
    virtual void set(T pos, bool val) = 0;
    virtual bool get(T pos) = 0;
};