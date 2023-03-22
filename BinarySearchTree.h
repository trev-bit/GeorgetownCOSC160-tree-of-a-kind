#include <iostream>
#include <fstream>
#include <vector>
#include <list>
#include <algorithm>

using namespace std;

struct bstNode 
{
    int data;
    int depth;
    bstNode* left;
    bstNode* right;

    bstNode(int x) : data(x), depth(0), left(NULL), right(NULL) {}
};

class BinarySearchTree
{
private:
    bstNode* root;
    int traversalCount;



    bstNode* findMinNode( bstNode* node );

    bstNode* deleteNode( bstNode* node, int data );
// 

public:
    BinarySearchTree();

    int getTraversalCount() { return traversalCount; } 
    bstNode* getRoot() { return root; }

    bstNode* insert( bstNode* node, int data );
    void insert( int data );

    bool search( int data );

    bstNode* deleteNode( int data );

    void printPreorder( bstNode* node );

    void printTree();

    void orderedPrint( bstNode* here );
    
};
