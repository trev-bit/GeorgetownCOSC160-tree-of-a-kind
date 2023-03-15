#include "BinarySearchTree.h"


BinarySearchTree::BinarySearchTree()
{
    root = NULL;

    bstNode* newNode = new bstNode;
    newNode->data = NULL;
    newNode->left = NULL;
    newNode->right = NULL;
}


bstNode* BinarySearchTree::insert( int data )
{
    bstNode* newNode = new bstNode;
    bstNode* peekNode = root;
    // creates a node if BST is empty
    if( peekNode == NULL )
    {
        newNode->data = data;
        newNode->left = NULL;
        newNode->right = NULL;
    }
    else if( data < peekNode->data )
    {
        peekNode->left = insert(data);
    }
    else if( data > peekNode->data ) 
    {
        peekNode->right = insert(data);
    }

    return newNode;
}


bstNode* BinarySearchTree::printOrderTree( bstNode* here )
{
    if ( here != nullptr ) 
    {
        printOrderTree(here->left);
        cout << here->data << " ";
        printOrderTree(here->right);
    }
}

