#ifndef LINKED_LIST_HPP
#define LINKED_LIST_HPP

#include<iostream>

template<class DataType>
class LinkedList {
  
  struct Node {
    DataType data;   
    Node* next;
    Node(const DataType &x) : data(x), next(nullptr) {} 
  };

  typedef struct Node* NodePtr;

  public:

    LinkedList() : head(nullptr), current(nullptr), temp(nullptr), size(0) {}

    void Add(const DataType& x) {
      NodePtr node = new Node(x);
      
      if(head != nullptr) {

        current = head;

        while(current->next != nullptr) {
          current = current->next;
        }
        current->next = node;           
      }
      else { // No elements yet
        head = node;
      }
      ++size;
    }

    void Remove(const DataType& x) {

      NodePtr target = nullptr;
      temp = head;
      current = head;

      while(current != nullptr && current->data != x) {
        temp = current;
        current = current->next;         
      }

      if(current == nullptr) {
        std::cout << x << " was not found in the list" << std::endl;
        delete target;
      }
      else{
        target = current;
        current = current->next;
        temp->next = current;

        if(target == head) {
          head = head->next;
          temp = nullptr;
          
        }
        delete target;
        --size;
      }
  
    }

    unsigned Size() { return size; }

    void Print() {
      current = head;
      while(current != nullptr) {
        std::cout << current->data << std::endl;
        current = current->next;
      }
    }
    

  private:

    NodePtr head;
    NodePtr current;
    NodePtr temp;
    unsigned size;

};

#endif // LINKED_LIST_HPP
