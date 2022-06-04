#pragma once 

class Slot;

class CollapseBehavior {
    public:
        virtual void collapse(Slot& slot) = 0;
};