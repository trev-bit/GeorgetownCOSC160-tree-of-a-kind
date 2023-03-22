#include <iostream>
#include <fstream>
#include <vector>
#include <list>
#include <algorithm>

using namespace std;

struct bstNode 
{
    int data;
    bstNode* left;
    bstNode* right;

    bstNode(int x) : data(x), left(NULL), right(NULL) {}
};

class BinarySearchTree
{
private:
    bstNode* root;
    int traversalCount;

    bstNode* insert( int data );

    bstNode* findMinNode( bstNode* node );

    bstNode* deleteNode( bstNode* node, int data );
// 

public:
    BinarySearchTree();

    int getTraversalCount() { return traversalCount; } 

    bstNode* insert(bstNode *node, int data);

    bool search( int data );

    bstNode* deleteNode( int data );

    void printPreorder( bstNode* node );

    void printTree();

    void orderedPrint( bstNode* here );
    
};

/*
#include <iostream>

class Node {
public:
    int key;
    Node* left;
    Node* right;
    
    Node(int key) {
        this->key = key;
        this->left = nullptr;
        this->right = nullptr;
    }
};

class BinarySearchTree {
public:
    BinarySearchTree() {
        this->root = nullptr;
    }
    
    void insert(int key) {
        Node* node = new Node(key);
        
        if (this->root == nullptr) {
            this->root = node;
        } else {
            Node* current = this->root;
            Node* parent = nullptr;
            
            while (current != nullptr) {
                parent = current;
                
                if (key < current->key) {
                    current = current->left;
                } else {
                    current = current->right;
                }
            }
            
            if (key < parent->key) {
                parent->left = node;
            } else {
                parent->right = node;
            }
        }
    }
    
    Node* search(int key) {
        Node* current = this->root;
        
        while (current != nullptr && current->key != key) {
            if (key < current->key) {
                current = current->left;
            } else {
                current = current->right;
            }
        }
        
        return current;
    }
    
    void inorder_traversal(Node* node) {
        if (node != nullptr) {
            inorder_traversal(node->left);
            std::cout << node->key << " ";
            inorder_traversal(node->right);
        }
    }
    
    void print_tree() {
        inorder_traversal(this->root);
        std::cout << std::endl;
    }
    
private:
    Node* root;
};

int main() {
    BinarySearchTree bst;
    
    bst.insert(5);
    bst.insert(3);
    bst.insert(7);
    bst.insert(1);
    bst.insert(4);
    bst.insert(6);
    bst.insert(8);
    
    bst.print_tree();
    
    Node* node = bst.search(6);
    
    if (node != nullptr) {
        std::cout << "Node found with key " << node->key << std::endl;
    } else {
        std::cout << "Node not found" << std::endl;
    }
    
    return 0;
}



*/