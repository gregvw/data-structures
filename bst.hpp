#ifndef BST_HPP
#define BST_HPP

#include<cstddef>

template<class KeyType>
struct Node {
  KeyType key;
  Node* left;
  Node* right;
  Node(const KeyType &k) : key(k), left(NULL), right(NULL) {}     
};


// KeyType must support < and == operators
template<class KeyType>
class BSTree {

  public: 

    typedef Node<KeyType> NodeType;
    typedef NodeType*     NodePtr;

    BSTree() : root(NULL), count(0) {}
    virtual ~BSTree() { DestroyTree(root);} 


    void Insert(const KeyType &key) {
      if(root != NULL)
        Insert(key, root);
      else {
        root = new NodeType(key);
        ++count;
      }
    } 

    void Remove(const KeyType &key) {

      Remove(key, root);  
    }

    NodePtr Search(const KeyType &key) {
      return Search(key,root);
    }        

    void Print() {
      Print(root);
    }    

    unsigned Size() {
      return count;
    }

    KeyType FindSmallest() {
      return FindSmallest(root); 
    }

  private:
    NodePtr root;
    unsigned count;

    void DestroyTree(NodePtr leaf) {
      if(leaf != nullptr) {
        DestroyTree(leaf->left);
        DestroyTree(leaf->right);
        delete leaf;
        --count;
      }
    } 

    void Insert(const KeyType &key, NodePtr leaf) {
      if(key < leaf->key) {
        if(leaf->left != nullptr)
          Insert(key,leaf->left);
        else {
          leaf->left = new NodeType(key);
          ++count;
        }
      } else if(key > leaf->key) {
        if(leaf->right != nullptr) 
          Insert(key, leaf->right);
        else {
          leaf->right = new NodeType(key);
          ++count;
        } 
      } 
    }    

    NodePtr Search(const KeyType &key, NodePtr leaf) {
      if(leaf != nullptr) {
        if(key == leaf->key)
          return leaf;
        if(key<leaf->key)
          return search(key,leaf->left);
        else
          return search(key,leaf->right);     
      } else return nullptr;
    }

    void Remove(const KeyType& key, NodePtr parent) {

      if(root != nullptr) {

        if(root->key == key) {
          RemoveRootMatch();
      
        } else {
          if(key < parent->key && parent->left != nullptr) {
            if(parent->left->key == key) {
              RemoveMatch(parent,parent->left,true);
            } else {
              Remove(key,parent->left);
            }            
          } 
          else if(key > parent->key & parent->right != nullptr) {
            if(parent->right->key == key) {
              RemoveMatch(parent,parent->right,false);
            } else {
              Remove(key,parent->right);
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

    void RemoveRootMatch() {
      if(root != nullptr) {
        NodePtr temp = root;
        KeyType rootKey = root->key;
        KeyType smallestRight; 
        
        // Leaf node case
        if(root->left == nullptr && root->right == nullptr) {
          root = nullptr;
          delete temp;
          --count;
        }  

        // Right child only case
        else if(root->left == nullptr && root->right != nullptr) {
          root = root->right;
          temp->right = nullptr;
          delete temp;
          --count;          
        }

        // Left child only case
        else if(root->right == nullptr && root->left != nullptr) {
          root = root->left;
          temp->left = nullptr;
          delete temp; 
          --count;
        }
 
        // Root has two children
        else {
          smallestRight = FindSmallest(root->right);
          Remove(smallestRight, root);
          root->key = smallestRight;
        }

      } else {
        std::cout << "Can't remove root (empty tree)" << std::endl;
      }
    }

    void RemoveMatch(NodePtr parent, NodePtr match, bool isLeft) {
      if(root != nullptr) {
        NodePtr temp;
        KeyType matchKey = match->key;
        KeyType smallestRight; 

        // Leaf node case
        if(match->left == nullptr && match->right == nullptr) {
          temp = match;
          isLeft ? parent->left = nullptr : parent->right = nullptr;
          delete temp;
          --count;
        }
       
        // Has right child only
        else if(match->left == nullptr && match->right != nullptr) {
          isLeft ? parent->left = match->right : parent->right = match->right;
          match->right = nullptr;
          delete temp;
          --count;
        }

        // Has left child only
        else if(match->left != nullptr && match->right == nullptr) {
          isLeft ? parent->left = match->left : parent->right = match->left;
          match->left = nullptr;
          delete temp;
          --count;
        }

        // Has both children
        else {
          smallestRight = FindSmallest(match->right);
          Remove(smallestRight,match);
          match->key = smallestRight;
        }

      } 
      else {
        std::cout << "Unexpected behavior in RemoveMatch" << std::endl;
      }
    }

    void Print(NodePtr leaf) {
      if(root != nullptr) {
        if(leaf->left != nullptr) {
          Print(leaf->left);
        }     
        std::cout << leaf->key << std::endl;   
        if(leaf->right != nullptr) {
          Print(leaf->right); 
        } 
      }
      else {
        std::cout << "Empty tree" << std::endl; 
      }
    }

    KeyType FindSmallest(NodePtr ptr) {
      if(ptr->left != nullptr) {
        return FindSmallest(ptr->left);
      }  
      else {
        return ptr->key;
      } 
    }

};



#endif

