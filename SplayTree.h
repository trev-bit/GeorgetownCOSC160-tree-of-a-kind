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

    sNode(int x) : data(x), depth(0), parent(NULL), left(NULL), right(NULL) {}
};

class SplayTree
{
private:
    sNode* root;
    int traversalCount;

    sNode* insert( sNode* node, int data );
    sNode* findMinNode( sNode* node );
    sNode* deleteNode( sNode* node, int data );

    void leftRotation( sNode* node );
    void rightRotation( sNode* node );

    sNode* getNode( int data );
    void splay( sNode* node );
    sNode* grabSearch( sNode* node, int data );
//
public:
    SplayTree();
    sNode* getRoot() { return root; }
    int getTraversalCount() { return traversalCount; } 

    void insert( int data );
    bool search( int data );

    bool binarySearch( int data );
    sNode* deleteNode( int data );

    void printPreorder( sNode* node );
//
};