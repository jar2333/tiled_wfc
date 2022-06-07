#pragma once 

class ISlot;

class ICollapseBehavior {
    public:
        virtual void collapse(ISlot& slot) = 0;
};