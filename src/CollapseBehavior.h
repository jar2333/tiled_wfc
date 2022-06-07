#pragma once 

class IGridSlot;

class ICollapseBehavior {
    public:
        virtual void collapse(IGridSlot& slot) = 0;
};