#include <iostream>
#include "bst.hpp"

int main(int argc, char *argv[]) {

  BSTree<int> tree;

  tree.insert(15);
  tree.insert(12);
  tree.insert(9);
  tree.insert(23);
  tree.insert(45);
  tree.insert(7);

  tree.print();
  std::cout << "Tree contains " << tree.size() << " nodes" << std::endl; 

  tree.remove(45);
  tree.print();
  std::cout << "Tree contains " << tree.size() << " nodes" << std::endl; 

}
