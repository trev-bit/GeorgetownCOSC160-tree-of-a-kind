#include "BinarySearchTree.h"

bstNode* BinarySearchTree::spotScout( bstNode *node, int data )
{
    // creates a node if BST is empty
    if( node == NULL )
    {
        node = new bstNode;
        node->data = data;
        node->left = NULL;
        node->right = NULL;
    }
    else if( data < node->data )
    {
        node->left = spotScout(node->left, data);
    }
    else if ( data > node->data ) 
    {
        node->right = spotScout(node->right, data);
    }

    return node;
}
