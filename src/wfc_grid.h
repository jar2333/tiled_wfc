#pragma once 

#include "grid.h"

class Slot;
class CollapseBehavior;
class WFCHeuristic;

class WFCGrid : public Grid<Slot> {
    public:
        virtual void collapse(WFCHeuristic& h) = 0;
        virtual void collapse(int key, CollapseBehavior& cb) = 0;
        virtual bool constrain(int current, int neighbor) = 0;
        virtual bool isCollapsed() = 0;
        virtual bool isContradiction() = 0;
};