#pragma once

template <class T>
class Grid {
  public:
    virtual int *getNeighbors() = 0;
    virtual T *getValue(int key) = 0;
    virtual T **getValues() = 0;
    virtual int *getKeys() = 0;
};