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
};

class BinarySearchTree
{
private:
    bstNode* root;

    bstNode* spotScout( bstNode* node, int data );


public:
    BinarySearchTree() { root = NULL; }

    void insert( int data ) { root = spotScout( root, data ); }

    
};