#pragma once 

class IGridSuperposition;

class ICollapseBehavior {
    public:
        virtual void collapse(IGridSuperposition& slot) = 0;
};