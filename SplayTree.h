#include <string>
#include <iostream>
#include <fstream>
#include <vector>
#include <list>
#include <algorithm>

using namespace std;

struct sNode
{
    int data;
    int depth;

    sNode* parent;
    sNode* left;
    sNode* right;

    sNode(int x) : data(x), depth(0), parent(nullptr), left(nullptr), right(nullptr) {}
};

class SplayTree
{
private:
    sNode* root;
    int traversalCount;

    sNode* insert( sNode* node, int data );
    sNode* findMinNode( sNode* node );
    sNode* findMaxNode( sNode* node );

    void leftRotation( sNode* node );
    void rightRotation( sNode* node );

    sNode* getNode( int data );
    void splay( sNode* node );
    sNode* grabSearch( sNode* node, int data );
    void deleteNode( sNode* node, int data );

    void split ( sNode* &x, sNode* &s, sNode* &t );
    sNode* join( sNode* s, sNode* t );
//
public:
    SplayTree();
    sNode* getRoot() { return root; }
    int getTraversalCount() { return traversalCount; } 

    void insert( int data );
    sNode* search( int data );

    bool binarySearch( int data );
    void deleteNode( int data );

    void printPreorder( sNode* node );
//
};