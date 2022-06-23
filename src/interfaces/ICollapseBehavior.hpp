#pragma once 

class ISuperposition;

class ICollapseBehavior {
    public:
        virtual void collapse(ISuperposition& superposition) = 0;
};