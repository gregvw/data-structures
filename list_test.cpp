#include "linkedlist.hpp"

int main(int argc, char *argv[]) {

  LinkedList<int> list;

  list.Add(5);
  list.Add(3);
  list.Add(9);
  list.Add(4);
  list.Add(7);
  list.Remove(3);
  list.Print();
  std::cout << "The list has " << list.Size() << " nodes" << std::endl;
}
