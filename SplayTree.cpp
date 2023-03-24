#include "SplayTree.h"

sNode *SplayTree::insert(sNode* node, int data)
{
    if ( node == NULL )
    {
        sNode* newNode = new sNode(data);
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

SplayTree::SplayTree()
{
    root = NULL;
}

void SplayTree::insert( int data )
{
    sNode* node = new sNode(data);

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


void SplayTree::printPreorder( sNode* node )
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

