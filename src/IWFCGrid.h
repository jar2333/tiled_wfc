#pragma once 

#include "Key.h"
#include "IGrid.h"

class IGridSuperposition;
class ICollapseBehavior;
class IWFCHeuristic;

class IWFCGrid : public IGrid<SuperpositionKeyT, IGridSuperposition> {
    public:
        virtual void collapse(IWFCHeuristic& h, ICollapseBehavior& cb) = 0;
        virtual void collapse(SuperpositionKeyT key, ICollapseBehavior& cb) = 0;
        virtual bool constrain(SuperpositionKeyT current_key, SuperpositionKeyT neighbor_key) = 0;
        virtual bool isCollapsed() = 0;
        virtual bool isContradiction() = 0;
};