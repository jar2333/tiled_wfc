#pragma once 

#include "IGrid.h"

class IGridSuperposition;
class ICollapseBehavior;
class IWFCHeuristic;

class IWFCGrid : public IGrid<IGridSuperposition> {
    public:
        virtual void collapse(IWFCHeuristic& h, ICollapseBehavior& cb) = 0;
        virtual void collapse(int key, ICollapseBehavior& cb) = 0;
        virtual bool constrain(int current_key, int neighbor_key) = 0;
        virtual bool isCollapsed() = 0;
        virtual bool isContradiction() = 0;
};