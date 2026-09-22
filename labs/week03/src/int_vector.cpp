#include "int_vector.hpp"

#include <stdexcept>

IntVector::~IntVector() {
    // Release the owned array exactly once.
    delete[] data_;
}

IntVector::IntVector(const IntVector& other) {
    //(void)other;
    // TODO: allocate independent storage and copy the logical elements.

    //Copy the size and capacity
    size_ = other.size_;
    capacity_ = other.capacity_;

    //Copy the elements into a separate storage
    if(capacity_ == 0){
        data_ = nullptr;
    } else {
        data_ = new int[capacity_];

        for(std::size_t x = 0; x < size_; x++){
            data_[x] = other.data_[x];
        }
    }

    check_invariant();

    //throw std::logic_error("TODO: implement IntVector copy construction");

}

void IntVector::check_invariant() const {
    // Assert the Week 3 representation invariants.

    //Check if `size_ <= capacity_`
    assert(size_ <= capacity_);

    //Check if zero capacity and `nullptr` agree with each other
    if(capacity_ == 0){
        assert(data_ == nullptr);
    } else{
        assert(data_ != nullptr);
    }
}

void IntVector::grow() {
    // Geometric growth policy: 0 -> 1, otherwise double capacity.
    // Preserve size_ and all existing logical elements.
   
   //Choose a larger capacity
    std::size_t newCapacity_ = 0;

    if(capacity_ == 0){
        newCapacity_ = 1;
    } else{
        newCapacity_ = capacity_ * 2;
    }

    //Allocate a new contiguous array
    int* newData_ = new int[newCapacity_];

    //Copy the existing logical elements

    for(std::size_t x = 0; x < size_; x++){
        newData_[x] = data_[x];
    }

    //Release the old allocation
    delete[] data_;

    //Update data_ and capacity_. Preserve size_
    data_ = newData_;
    capacity_ = newCapacity_;

    //Verify the invariant;
    check_invariant();


    //throw std::logic_error("TODO: implement IntVector::grow");
}

void IntVector::push_back(int value) {
    (void)value;
    // Grow only when size_ == capacity_, append, update size_,
    // and finish in a valid representation state.
    if(size_ == capacity_){
        grow();
    }

    //Store value at index size_

    data_[size_] = value;
    
    //Increment size_
    size_ += 1;
    //Check invariant
    check_invariant();

    //throw std::logic_error("TODO: implement IntVector::push_back");
}
