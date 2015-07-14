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

    LinkedList() : head(nullptr), 
                   current(nullptr), 
                   temp(nullptr), 
                   numberOfNodes(0) {}

    void add(const DataType& x) {
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
      ++numberOfNodes;
    }  // add()


    void remove(const DataType& x) {

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
        --numberOfNodes;
      }
  
    } // remove()


    void reverse() {

      if(numberOfNodes > 1) {

        NodePtr ptr = head;
        current = head->next;
        temp = nullptr;

        if(current->next != nullptr) {
          temp = current->next;
        }

        head->next = nullptr;

        while(temp->next != nullptr) {
          current->next = ptr;
          ptr = current;
          current = temp;
          temp = temp->next;
        } 
        current->next = ptr;
        head = temp;
        temp->next = current;
      }    

    } // reverse()


    DataType getMin() {

      if(head != nullptr) {
        current = head; 
        DataType minimum = current->data;
        while(current != nullptr) {
          if(current->data < minimum) {
            minimum = current->data;
          }
          current = current->next;
        }       
        return minimum;  
      }
      else {
        std::cout << "The list is empty" << std::endl;
        DataType minimum(0); 
        return minimum;  
      }
    } // getMin()


    DataType getMax() {

      if(head != nullptr) {
        current = head; 
        DataType maximum = current->data;
        while(current != nullptr) {
          if(current->data > maximum) {
            maximum = current->data;
          }
          current = current->next;
        }       
        return maximum;  
      }
      else {
        std::cout << "The list is empty" << std::endl;
        DataType maximum(0); 
        return maximum;  
      }
    } // getMax()



    unsigned size() { return numberOfNodes; }

    void print() {
      current = head;
      while(current != nullptr) {
        std::cout << current->data << std::endl;
        current = current->next;
      }
    } // print()
    
    

  private:

    NodePtr head;
    NodePtr current;
    NodePtr temp;
    unsigned numberOfNodes;

};

#endif // LINKED_LIST_HPP
