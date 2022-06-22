#pragma once

#include "Key.h"

#include <vector>
#include <memory>

template <typename KT, class T>
class IGrid {
  public:
    virtual std::vector<KT> getNeighbors(KT key) = 0;
    virtual std::shared_ptr<T> getValue(KT key) = 0;
    virtual std::vector<KT> getKeys() = 0;
};