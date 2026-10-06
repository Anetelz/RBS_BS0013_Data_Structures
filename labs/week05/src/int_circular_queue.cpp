#include "int_circular_queue.hpp"

#include <cassert>
#include <stdexcept>

namespace {
[[noreturn]] void todo(const char* operation) {
    throw std::logic_error(operation);
}
}  // namespace

IntCircularQueue::IntCircularQueue(std::size_t capacity)
    : data_(capacity) {
    assert(capacity > 0);
    check_invariant();
}

bool IntCircularQueue::empty() const {
    return size_ == 0;
}

bool IntCircularQueue::full() const {
    return size_ == data_.size();
}

std::size_t IntCircularQueue::size() const {
    return size_;
}

std::size_t IntCircularQueue::capacity() const {
    return data_.size();
}

int& IntCircularQueue::front() {
    assert(!empty());
    //Returns the front element
    return data_[front_];
}

const int& IntCircularQueue::front() const {
    assert(!empty());
    //Returns the front element
    return data_[front_];
}

int& IntCircularQueue::back() {
    assert(!empty());
    //Returns the back element
    return data_[physical_index(size_ -1)];
}

const int& IntCircularQueue::back() const {
    assert(!empty());
    //Returns the back element
    return data_[physical_index(size_ -1)];
}

void IntCircularQueue::enqueue(int value) {
    assert(!full());
    //Stores the value in data_
    data_[(front_ + size_) % capacity()] = value;
    size_++;
    check_invariant();
}

void IntCircularQueue::dequeue() {
    assert(!empty());

    //Ignores the current first_ value, changes the next value to be the first_
    front_ = (front_ + 1) % capacity();
    size_--;

    check_invariant();
}

void IntCircularQueue::clear() {
    size_ = 0;
    front_ = 0;
    check_invariant();
}

std::size_t IntCircularQueue::physical_index(std::size_t logical_index) const {
    assert(logical_index < size_);
    //Clalculates and returns the physical index based on the given logical index
    return (front_ + logical_index) % capacity();
}

void IntCircularQueue::check_invariant() const {
    //Checking if backing storage is non-empty
    assert(capacity() != 0);
    //Checking if `front_` is a valid physical index
    assert(front_ < capacity());
    //Checking if `size_` does not exceed capacity
    assert(size_ <= capacity());
}
