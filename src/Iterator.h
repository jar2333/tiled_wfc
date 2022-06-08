#pragma once

#include <iterator>
 
template<typename cat_t, typename diff_t, typename val_t, typename ptr_t, typename ref_t>
class Iterator {

    public:
        using iterator_category = cat_t;
        using difference_type   = diff_t;
        using value_type        = val_t;
        using pointer           = ptr_t;
        using reference         = ref_t;

        Iterator(value_type i);

        virtual reference operator*() = 0;
        virtual pointer operator->() = 0;
        virtual Iterator& operator++() = 0;  
        virtual Iterator operator++(int) = 0;
        virtual friend bool operator== (const Iterator& a, const Iterator& b) = 0;
        virtual friend bool operator!= (const Iterator& a, const Iterator& b) = 0;  

    private:
        value_type i;
};