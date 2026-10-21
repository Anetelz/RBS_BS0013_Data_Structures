#include "int_hash_map.hpp"
#include <cassert>
#include <stdexcept>

namespace
{
    [[noreturn]] void todo(const char *operation) { throw std::logic_error(operation); }
}

IntHashMap::IntHashMap(std::size_t capacity) : slots_(capacity)
{
     assert(capacity > 0); 
}

double IntHashMap::load_factor() const noexcept {
     return static_cast<double>(size_) / static_cast<double>(capacity());
}

std::size_t IntHashMap::bucket(int key) const
{   // Calculates the most appropriate possible bucket for the key
    assert(key >= 0);
    std::size_t calculatedBucket = key % capacity(); //Keys are non-negative integers. 
    return calculatedBucket;

}

std::size_t IntHashMap::find_index(int key) const
{   // Finds the exact index of the array where the key is stored if the key is found
    assert(key >= 0);

    std::size_t start = bucket(key);
    std::size_t cap = capacity();
    
    for(std::size_t i = 0; i < cap; i++){
        std::size_t index = (start + i) % cap;

        if (slots_[index].state == SlotState::Empty)
            return cap;

        if (slots_[index].state == SlotState::Occupied && slots_[index].key == key)
            return index;
    }

    return cap;
}

bool IntHashMap::contains(int key) const {
     return find(key) != nullptr;
 }

int *IntHashMap::find(int key)
{ //Rerurns the address of the key
    std::size_t index = find_index(key);

    if(index == capacity()){
        return nullptr;
    }

    int* value_address = &slots_[index].value;
    return value_address;
}

const int *IntHashMap::find(int key) const
{    //Rerurns the address of the key
    std::size_t index = find_index(key);

    if(index == capacity()){
        return nullptr;
    }

    return &slots_[index].value;
}

bool IntHashMap::insert_or_assign(int key, int value)
{
    assert(key >= 0);

    std::size_t cap = capacity();
    std::size_t start = bucket(key);
    std::size_t first_deleted = cap; // the first deleted slots index (no index can be equal to the capacity)

    for (std::size_t i = 0; i < cap; i++) {
        std::size_t index = (start + i) % cap; // the current slot index

        if (slots_[index].state == SlotState::Occupied) {
            if (slots_[index].key == key) {
                slots_[index].value = value;
                return false; // no new key inserted, reasigned value
            }
        }
        else if (slots_[index].state == SlotState::Deleted) {
            if (first_deleted == cap) {
                first_deleted = index; // remember the index of the first deleted 
            }
        }
        else if (slots_[index].state == SlotState::Empty) {
            if(first_deleted != cap){
                slots_[first_deleted].key = key;
                slots_[first_deleted].value = value;
                slots_[first_deleted].state = SlotState::Occupied;
                
            } else{
                slots_[index].key = key;
                slots_[index].value = value;
                slots_[index].state = SlotState::Occupied;
            }

            size_++;
            return true; // A new key and value was inserted
        }
    }

    if(first_deleted != cap){
        slots_[first_deleted].key = key;
        slots_[first_deleted].value = value;
        slots_[first_deleted].state = SlotState::Occupied;
        size_++;
        return true; // A new key and value was inserted
    }

    throw std::overflow_error("No available slots");

}

bool IntHashMap::erase(int key)
{
    std::size_t start = bucket(key);
    std::size_t cap = capacity();
    
    for(std::size_t i = 0; i < cap; i++){
        std::size_t index = (start + i) % cap;

        if(slots_[index].state == SlotState::Empty){
            return false; 
        } else if(slots_[index].state == SlotState::Occupied && slots_[index].key == key){
            slots_[index].state = SlotState::Deleted;
            size_--;
            return true;
        }

    }
    return false;
}

std::size_t IntHashMap::probe_count(int key) const
{
    /*Count inspected slots until the key is found, Empty proves absence, or the entire table has been inspected.*/
    assert(key >= 0);

    std::size_t start = bucket(key);
    std::size_t cap = capacity();

    for (std::size_t i = 0; i < cap; i++) {
        std::size_t index = (start + i) % cap; //current slot index

        if (slots_[index].state == SlotState::Empty) {
            return i + 1; //Return how many slots have been inspected, includuing this slot
        }

        if (slots_[index].state == SlotState::Occupied && slots_[index].key == key) {
            return i + 1; //Return how many slots have been inspected, includuing this slot
        }
    }

    return cap; //The entire table has been inspected

}

bool IntHashMap::check_invariant() const {

    std::size_t occupied_count = 0;
    std::size_t cap = capacity();

    for(std::size_t i = 0; i < cap; i++){
        if(slots_[i].state != SlotState::Occupied){ //Current slot not occupied
            continue;
        }

        //Else if current slot is occupied
        occupied_count++; 

        //Checks whether every occupied key is non-negative
        if(slots_[i].key < 0){
            return false;
        }

        //Checks whether every occupied key is discoverable at that exact slot through the normal probe rule
        std::size_t start = bucket(slots_[i].key); //Finds the initial index of the current slots' key
        bool found = false;

        //Tries to find the key through the normal probe rule
        for(std::size_t x = 0; x < cap; x++){
            std::size_t index = (start + x) % cap; //Slot index

            if(slots_[index].state == SlotState::Empty){ //If the key is not found
                break;
            }

            if(index == i){ //If the key is found
                found = true;
                break;
            }
        }

        if(!found){
            return false;
        }


    }

    return occupied_count == size_;    
}
