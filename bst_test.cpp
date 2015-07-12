#include<iostream>
#include"bst.hpp"

int main(int argc, char *argv[]) {

  BSTree<int> tree;

  tree.Insert(15);
  tree.Insert(12);
  tree.Insert(9);
  tree.Insert(23);
  tree.Insert(45);
  tree.Insert(7);

  tree.Remove(45);

  tree.Print();


  std::cout << "Tree contains " << tree.Size() << " nodes" << std::endl; 

}
