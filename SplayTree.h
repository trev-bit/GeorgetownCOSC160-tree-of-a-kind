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
//
public:
    SplayTree();
    sNode* getRoot() { return root; }

    void insert( int data );

    void printPreorder( sNode* node );
//
};