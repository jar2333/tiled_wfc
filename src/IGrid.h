#pragma once

#include <vector>
#include <memory>

template <class T>
class IGrid {
  public:
    virtual std::vector<int> getNeighbors(int key) = 0;
    virtual std::shared_ptr<T> getValue(int key) = 0;
    virtual std::vector<int> getKeys() = 0;
};