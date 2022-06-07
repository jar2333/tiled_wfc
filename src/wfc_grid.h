#pragma once 

#include "grid.h"

class ISlot;
class ICollapseBehavior;
class IWFCHeuristic;

class IWFCGrid : public IGrid<ISlot> {
    public:
        virtual void collapse(IWFCHeuristic& h) = 0;
        virtual void collapse(int key, ICollapseBehavior& cb) = 0;
        virtual bool constrain(int current, int neighbor) = 0;
        virtual bool isCollapsed() = 0;
        virtual bool isContradiction() = 0;
};