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

sNode* SplayTree::findMinNode( sNode* min )
{        
    while( min->left )
    {
        min = min->left;
    }
    return min;
}


sNode* SplayTree::deleteNode( sNode* node, int data )
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
            sNode* temp = node->right;
            delete node;

            return temp;
        }
        else if( !node->right )
        {
            sNode* temp = node->left;
            delete node;

            return temp;
        }

        sNode* temp = findMinNode(node->right);
        node->data = temp->data;
        node->right = deleteNode(node->right, temp->data);
    }

    return node;
}

// END PRIVATE MEMBER FUNCTIONS
//                              
// BEGIN PUBLIC MEMBER FUNCTIONS

SplayTree::SplayTree()
{
    root = NULL;
    traversalCount = 0;
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


sNode* SplayTree::deleteNode( int data )
{
    root = deleteNode( root, data );

    return root;
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

