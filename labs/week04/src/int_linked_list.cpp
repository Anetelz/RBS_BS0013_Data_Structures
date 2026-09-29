#include "int_linked_list.hpp"

#include <stdexcept>

/*
namespace {
[[noreturn]] void todo(const char* operation) {
    throw std::logic_error(operation);
}
}  // namespace
*/

IntLinkedList::~IntLinkedList() {
    clear();
}

int& IntLinkedList::front() {
    //On an empty list, throw `std::out_of_range`.
   if(size_ == 0){
    throw std::out_of_range("The list is empty!");
   } 

   //On a non-empty list, return a reference to the first value;
   return head_->value;
}

const int& IntLinkedList::front() const {
   if(size_ == 0){
    throw std::out_of_range("The list is empty!");
   } 

   return head_->value;
}

int& IntLinkedList::back() {
    //On an empty list, throw `std::out_of_range`.
   if(size_ == 0){
    throw std::out_of_range("The list is empty!");
   } 

   //On a non-empty list, return a reference to the last value;
   return tail_->value;
}

const int& IntLinkedList::back() const {
   if(size_ == 0){
    throw std::out_of_range("The list is empty!");
   } 

   return tail_->value;
}

void IntLinkedList::push_front(int value) {
    //Allocate new node, point the new_node->next to head_ 
    Node* new_node = new Node{value, head_};
    head_ = new_node;
    
    //Update size;
    size_++;

    //Repair tail_ if list was empty
    if(tail_ == nullptr){
        tail_ = new_node;
    }
}

void IntLinkedList::push_back(int value) {

    // Allocate new node
    Node* new_node = new Node{value, nullptr};
  
    if(head_ == nullptr){ //If the list was empty
        head_= new_node;
        tail_ = new_node;
    } else{
        // Point the current tail_ to the new node
        tail_->next = new_node;
        tail_ = new_node;
    }

    // Update size_
    size_++;
 
}

void IntLinkedList::pop_front() {
   
    // On an empty list, throw `std::out_of_range`
    if(size_ == 0){
        throw std::out_of_range("The list is empty!");
    } 

    // Preserve the successor before deleting the old first node
    Node* old_head = head_; //remember victim
    head_ = head_->next; //update successor
    delete old_head; //delete victim

    //Decrement `size_`;
    size_--;

    // If the removed node was the only node, restore `tail_ == nullptr`.
    if(size_ == 0){
        tail_ = nullptr;
    } 
}

bool IntLinkedList::contains(int value) const noexcept {
    //Start at `head_`, follow `next`, and stop when either the value is found or the chain ends.
    Node* current = head_;

    while(current != nullptr){
        if(current->value == value){
            return true;
        }
        current = current->next; // move to the next node
    }

    return false; // if no matching value is found
}

bool IntLinkedList::insert_after_first(int target, int value) {

    //Search from `head_` for the first node whose value equals `target`;
    Node* current = head_;

    while(current != nullptr){

        if(current->value == target){  

            //Insert one new node immediately after it;
            Node* new_node = new Node{value, current->next};
            current->next = new_node;

            //Update `tail_` if insertion occurs after the current tail;
            if(current == tail_){
                tail_ = new_node;
            }

            //Increment `size_`;
            size_++;

            //Return `true`.
            return true;
        }

        current = current->next; // move to the next node
    }

    //If no target node exists, return `false`;
    return false;
    
}

bool IntLinkedList::erase_after_first(int target) {
    Node* current = head_;

    while(current != nullptr){

        if(current->value == target){  //find the first node whose value equals `target`

            // Return `false` if the target node has no successor
            if(current->next == nullptr){
                return false;
            }

            // Remove exactly the successor node
            Node* victim_node = current->next;
            current->next = victim_node->next;
            delete victim_node;

            // Update `tail_` if the removed node was the tail
            if(current->next == nullptr){
                tail_ = current;
            }

            // Decrement `size_`
            size_--;

            return true;
        }

        current = current->next; // move to the next node
    }

    // Return `false` if the target is absent
    return false;
    
}

void IntLinkedList::clear() noexcept {
    // Release every reachable node exactly once, then restore empty state.

    while (head_ != nullptr){
        Node* old_head = head_;
        head_ = head_->next;
        delete old_head;
    }

    tail_ = nullptr;
    size_ = 0;   

}

bool IntLinkedList::check_invariant() const noexcept {
    // Verify empty/non-empty state, reachability, tail, count, and no cycle.
   
    //Check empty metadata consistency
    if(size_ == 0){
        return tail_ == nullptr && head_ == nullptr; // If size = 0, we only need to check this
    }

    //Check non-empty metadata consistency
    if(head_ == nullptr || tail_ == nullptr){ //If size > 0, then this should not be the case
        return false;
    }

    //Check whether reachable-node count equals `size_`
    std::size_t count_size = 0;
    Node* current = head_;

    while(current != nullptr && count_size <= size_){
        count_size++;
        current = current->next;
    }

    if(count_size != size_){
        return false;
    }

    //Check whether the final reachable node is `tail_`
    return tail_->next == nullptr;
}
