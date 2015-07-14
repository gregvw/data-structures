#include "linkedlist.hpp"

int main(int argc, char *argv[]) {

  LinkedList<int> list;

  list.add(5);
  list.add(3);
  list.add(9);
  list.add(4);
  list.add(7);
  list.reverse();
  list.print();
  
  std::cout << "The list has " << list.size() << " nodes" << std::endl;
  std::cout << "The smallest element is " << list.getMin() << std::endl;
  std::cout << "The largest element is " << list.getMax() << std::endl;

}
