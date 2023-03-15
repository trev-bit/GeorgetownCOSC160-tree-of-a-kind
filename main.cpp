#include "main.h"

using namespace std;

int main( int argc, const char* argv[] )
{
  string inputFile;

  inputFile = argv[1];

  string dummyplugFile = "p3_test0.txt";

  BinarySearchTree bst;

  cout << endl;
  
  ifstream portal1( dummyplugFile );
  int value;

  while( portal1 >> value )
  {
    if( portal1.peek() == '$' )
    {
      portal1.ignore();
    }
    else
    {
      bst.insert(value);
    }
  }

  bstNode* point = bst;

  bst.printOrderTree();



  return 0;
}