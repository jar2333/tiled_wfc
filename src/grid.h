#pragma once

#include <vector>
#include <memory>

template <class T>
class Grid {
  public:
    virtual std::vector<int> getNeighbors() = 0;
    virtual std::shared_ptr<T> getValue(int key) = 0;
    virtual std::vector<std::shared_ptr<T>> getValues() = 0;
    virtual std::vector<int> getKeys() = 0;
};