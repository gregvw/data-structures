#ifndef BST_HPP
#define BST_HPP

#include "LinkedList.hpp"

template<class KeyType>
struct Node {
  KeyType key;
  Node* left;
  Node* right;
  Node(const KeyType &k) : key(k), left(nullptr), right(nullptr) {}     
};


// KeyType must support < and == operators
template<class KeyType>
class BSTree {

  public: 

    typedef Node<KeyType> NodeType;
    typedef NodeType*     NodePtr;

    BSTree() : root(nullptr), numberOfNodes(0) {}
    virtual ~BSTree() { destroyTree(root);} 


    void insert(const KeyType &key) {
      if(root != nullptr)
        insert(key, root);
      else {
        root = new NodeType(key);
        ++numberOfNodes;
      }
    } // Insert() 

    void remove(const KeyType &key) {

      remove(key, root);  

    } // Remove()


    NodePtr search(const KeyType &key) {

      return search(key,root);

    } // Search()        


    void print() {

      print(root);

    } // print()    


    unsigned size() {

      return numberOfNodes;

    } // Size()


    KeyType getMin() {

      return getMin(root); 

    } 

  private:
    NodePtr root;
    unsigned numberOfNodes;

    void destroyTree(NodePtr leaf) {
      if(leaf != nullptr) {
        destroyTree(leaf->left);
        destroyTree(leaf->right);
        delete leaf;
        --numberOfNodes;
      }
    } 

    void insert(const KeyType &key, NodePtr leaf) {
      if(key < leaf->key) {
        if(leaf->left != nullptr)
          insert(key,leaf->left);
        else {
          leaf->left = new NodeType(key);
          ++numberOfNodes;
        }
      } else if(key > leaf->key) {
        if(leaf->right != nullptr) 
          insert(key, leaf->right);
        else {
          leaf->right = new NodeType(key);
          ++numberOfNodes;
        } 
      } 
    }    

    NodePtr search(const KeyType &key, NodePtr leaf) {
      if(leaf != nullptr) {
        if(key == leaf->key)
          return leaf;
        if(key<leaf->key)
          return search(key,leaf->left);
        else
          return search(key,leaf->right);     
      } else return nullptr;
    }

    void remove(const KeyType& key, NodePtr parent) {

      if(root != nullptr) {

        if(root->key == key) {
          removeRootMatch();
      
        } else {
          if(key < parent->key && parent->left != nullptr) {
            if(parent->left->key == key) {
              removeMatch(parent,parent->left,true);
            } else {
              remove(key,parent->left);
            }            
          } 
          else if(key > parent->key & parent->right != nullptr) {
            if(parent->right->key == key) {
              removeMatch(parent,parent->right,false);
            } else {
              remove(key,parent->right);
            }            
          }
          else {
            std::cout << "Key " << key << "not found" << std::endl; 
          }
        }
      } else {
        std::cout << "The tree is empty" << std::endl;
      }   
    }

    void removeRootMatch() {
      if(root != nullptr) {
        NodePtr temp = root;
        KeyType rootKey = root->key;
        KeyType smallestRight; 
        
        // Leaf node case
        if(root->left == nullptr && root->right == nullptr) {
          root = nullptr;
          delete temp;
          --numberOfNodes;
        }  

        // Right child only case
        else if(root->left == nullptr && root->right != nullptr) {
          root = root->right;
          temp->right = nullptr;
          delete temp;
          --numberOfNodes;          
        }

        // Left child only case
        else if(root->right == nullptr && root->left != nullptr) {
          root = root->left;
          temp->left = nullptr;
          delete temp; 
          --numberOfNodes;
        }
 
        // Root has two children
        else {
          smallestRight = getMin(root->right);
          remove(smallestRight, root);
          root->key = smallestRight;
        }

      } else {
        std::cout << "Can't remove root (empty tree)" << std::endl;
      }
    }

    void removeMatch(NodePtr parent, NodePtr match, bool isLeft) {
      if(root != nullptr) {
        NodePtr temp;
        KeyType matchKey = match->key;
        KeyType smallestRight; 

        // Leaf node case
        if(match->left == nullptr && match->right == nullptr) {
          temp = match;
          isLeft ? parent->left = nullptr : parent->right = nullptr;
          delete temp;
          --numberOfNodes;
        }
       
        // Has right child only
        else if(match->left == nullptr && match->right != nullptr) {
          isLeft ? parent->left = match->right : parent->right = match->right;
          match->right = nullptr;
          delete temp;
          --numberOfNodes;
        }

        // Has left child only
        else if(match->left != nullptr && match->right == nullptr) {
          isLeft ? parent->left = match->left : parent->right = match->left;
          match->left = nullptr;
          delete temp;
          --numberOfNodes;
        }

        // Has both children
        else {
          smallestRight = getMin(match->right);
          remove(smallestRight,match);
          match->key = smallestRight;
        }

      } 
      else {
        std::cout << "Unexpected behavior in RemoveMatch" << std::endl;
      }
    }

    void print(NodePtr leaf) {
      if(root != nullptr) {
        if(leaf->left != nullptr) {
          print(leaf->left);
        }     
        std::cout << leaf->key << std::endl;   
        if(leaf->right != nullptr) {
          print(leaf->right); 
        } 
      }
      else {
        std::cout << "Empty tree" << std::endl; 
      }
    }

    KeyType getMin(NodePtr ptr) {
      if(ptr->left != nullptr) {
        return getMin(ptr->left);
      }  
      else {
        return ptr->key;
      } 
    }

};



#endif

