#pragma once 

#include "Key.h"

#include <memory>

class IGridSuperposition;
class ICollapseBehavior;
class IHeuristic;

class IGridIterator {
    public:
        virtual SuperpositionKeyT getNext() = 0;
        virtual bool hasNext() = 0;
};

class IGrid {
    public:
        virtual void collapse(IHeuristic& h, ICollapseBehavior& cb) = 0;
        virtual void collapse(SuperpositionKeyT key, ICollapseBehavior& cb) = 0;
        virtual bool constrain(SuperpositionKeyT current_key, SuperpositionKeyT neighbor_key) = 0;
        virtual bool isCollapsed() = 0;
        virtual bool isContradiction() = 0;

        virtual std::unique_ptr<IGridIterator> getIterator() = 0;
};