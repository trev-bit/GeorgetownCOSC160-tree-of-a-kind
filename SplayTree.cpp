#include "SplayTree.h"
 

sNode* SplayTree::insert( sNode* node, int data )
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


sNode *SplayTree::findMaxNode( sNode* max )
{
    while( max->left )
    {
        max = max->left;
    }
    return max;
}


void SplayTree::leftRotation( sNode* node )
{
    sNode* orbit = node->right;
    node->right = orbit->left;

    if( orbit->left )
    {
        orbit->left->parent = node;
    }

    orbit->parent = node->parent;
    
    if( !node->parent )
    {
        root = orbit;
    }
    else if( node == node->parent->left )
    {
        node->parent->left = orbit;
    }
    else
    {
        node->parent->right = orbit;
    }

    orbit->left = node;
    node->parent = orbit;
    //
}


void SplayTree::rightRotation( sNode* node )
{
    sNode* orbit = node->left;
    node->left = orbit->right;

    if( orbit->right )
    {
        orbit->right->parent = node;
    }

    orbit->parent = node->parent;

    if( !node->parent )
    {
        root = orbit;
    }
    else if( node == node->parent->right )
    {
        node->parent->right = orbit;
    }
    else
    {
        node->parent->left = orbit;
    }

    orbit->right = node;
    node->parent = orbit;
    //
}

sNode* SplayTree::getNode( int data )
{
    sNode* node = root;

    while( node )
    {
        traversalCount++;
        if( data == node->data )
        {
            return node;
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

    return node;
}

void SplayTree::splay( sNode *node )
{
    while( node->parent )
    {
        // zig step variation
        if( !node->parent->parent )
        {
            if( node == node->parent->left )
            {
                rightRotation(node->parent);
            }
            else
            {
                leftRotation(node->parent);
            }
        } // zig-zig step variation
        else if( node == node->parent->left && node->parent == node->parent->parent->left )
        {
            rightRotation(node->parent->parent);
            rightRotation(node->parent);
        } // 
        else if( node == node->parent->right && node->parent == node->parent->parent->right )
        {
            leftRotation(node->parent->parent);
            leftRotation(node->parent);
        } // zig-zag step variation
        else if( node == node->parent->left && node->parent == node->parent->parent->right )
        {
            leftRotation(node->parent);
            rightRotation(node->parent);
        }
        else
        {
            rightRotation(node->parent);
            leftRotation(node->parent);
        }
    }
}


sNode* SplayTree::grabSearch( sNode* node, int data )
{
    if( !node || data == node->data )
    {
        return node;
    }

    if( data < node->data )
    {
        return grabSearch(node->left, data);
    }

    return grabSearch(node->right, data);
}


void SplayTree::deleteNode( sNode* node, int data )
{
    sNode* anchor = nullptr;
    sNode* link1;
    sNode*link2;

    while ( node )
    {
        if( node->data == data )
        {
            anchor = node;
        }

        if ( node->data <= data )
        {
            node = node->right;
        }
        else
        {
            node = node->left;
        }
    }

    if( !anchor )
    {
        cout << "oops" << endl;
        return;
    }

    split(anchor,link2, link1);

    if(link2->left )
    {
       link2->left->parent = NULL;
    }

    root = join(link2->left, link1);

    delete(link2);

   link2 = NULL;
//
}



void SplayTree::split( sNode* &anchor, sNode* &link2, sNode* &link1 )
{
    splay(anchor);

    if ( anchor->right )
    {
        link1= anchor->right;
        link1->parent = nullptr;
    }
    else
    {
        link1= nullptr;
    }

    link2 = anchor;
    link2->right = nullptr;
    anchor = nullptr;
    //
}

sNode *SplayTree::join( sNode* link2, sNode*link1)
{
    if (!link2) 
    {
        return link1;
    }

    if (!link1) 
    {
        return link2;
    }

    sNode* anchor = findMaxNode(link2);
    splay(anchor);
    anchor->right = link2;
    link2->parent = anchor;
    return anchor;
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
    sNode* other = NULL;
    sNode* rootDecoy = root;

    while ( rootDecoy ) 
    {
        other = rootDecoy;

        if ( node->data < rootDecoy->data ) 
        {
            rootDecoy = rootDecoy->left;
        } 
        else 
        {
            rootDecoy = rootDecoy->right;
        }
    }

    node->parent = other;

    if ( !other ) 
    {
        root = node;
    } 
    else if ( node->data < other->data ) 
    {
        other->left = node;
    } 
    else 
    {
        other->right = node;
    }

    splay(node);
    //
}

bool SplayTree::search( int data )
{
    sNode* node = grabSearch(root, data);

    if( node )
    {
        splay(node);
        return true;
    }

    return false;
}

bool SplayTree::binarySearch( int data )
{
    sNode* node = root;

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


void SplayTree::deleteNode( int data )
{
    deleteNode( root, data );
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
        if( node->right && !node->left )
        {
            cout << "[]";
        }
        printPreorder(node->left);
        if( node->left && !node->right )
        {
            cout << "[]";
        }
        printPreorder(node->right);
        
        cout << "]";
    }
    //
}

