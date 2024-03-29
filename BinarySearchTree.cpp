#include "BinarySearchTree.h"


bstNode* BinarySearchTree::insert( bstNode* node, int data )
{  
    if ( node == NULL )
    {
        bstNode* newNode = new bstNode(data);
        newNode->depth = newNode->depth + 1;
        return newNode;
    }

    traversalCount++;
    
    if ( data > node->data )
    {
        node->depth = node->depth + 1;
        node->right = insert(node->right, data);
    }
    else if( data < node->data )
    {
        node->depth = node->depth + 1;
        node->left = insert(node->left, data);
    }

    return node;
}


bstNode* BinarySearchTree::findMinNode( bstNode* min )
{        
    while( min->left )
    {
        min = min->left;
    }
    return min;
}


bstNode* BinarySearchTree::deleteNode( bstNode *node, int data )
{
    traversalCount++;

    if( !node )
    {
        return nullptr;
    }

// IF break for clarity

    if( data < node->data )
    {
        node->left = deleteNode(node->left, data);
    }    
    else if( data > node->data )
    {
        node->right = deleteNode(node->right, data);
    }
    else
    {
        if( !node->left )
        {
            bstNode* temp = node->right;
            delete node;

            return temp;
        }
        else if( !node->right )
        {
            bstNode* temp = node->left;
            delete node;

            return temp;
        }

        bstNode* temp = findMinNode(node->right);
        node->data = temp->data;
        node->right = deleteNode(node->right, temp->data);
    }

    return node;
}


// end of private member function implementation
// begining of public member function implementation


BinarySearchTree::BinarySearchTree()
{
    root = NULL;
    traversalCount = 0;
}


void BinarySearchTree::insert( int data )
{
    bstNode* node = new bstNode(data);

    if( root == NULL )
    {
        root = node;
    }
    else if( data < root->data )
    {
        root->left = insert(root->left, data);
    }
    else if( data > root->data )
    {
        root->right = insert(root->right, data);
    }
    //
}


bool BinarySearchTree::search( int data )
{
    bstNode* node = root;

    while( node )
    {
        traversalCount++;
        if( data == node->data )
        {
            return true;
        }
        else if( data < node->data )
        {
            node = node->left;
        }
        else
        {
            node = node->right;
        }
    }

    return false;
}


bstNode* BinarySearchTree::deleteNode( int data )
{
    root = deleteNode( root, data );

    return root;
}


void BinarySearchTree::printPreorder( bstNode* node )
{
    if( !node )
    {
        return;
    }
    else
    {
        cout << "[";
        cout << node->data;
        printPreorder(node->left);
        printPreorder(node->right);
        if( (node->left && !node->right) || node->right && !node->left)
        {
            cout << "[]";
        }
        cout << "]";
    }
    //
}


void BinarySearchTree::orderedPrint( bstNode* parent )
{
    if( parent )
    {
        orderedPrint(parent->left);

        cout << parent->data << " ";

        orderedPrint(parent->right);
  
    }
    //
}

