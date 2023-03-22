#include "main.h"

using namespace std;

int main( int argc, const char* argv[] )
{
  string inputFile;

  //inputFile = argv[1];

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
      bstNode* fill = new bstNode(value);
      bst.insert(fill, value);
      // cout << "MAIN UNIT TESTING - VALUE INSERTED: " << fill->data << endl;
    }
  }

  bst.printTree();


  return 0;
}