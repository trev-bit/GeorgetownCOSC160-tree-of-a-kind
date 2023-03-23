#include "main.h"

using namespace std;

int main( int argc, const char* argv[] )
{
  string inputFile;

  //inputFile = argv[1];

  string dummyplugFile = "p3_test4.txt";

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
      // cout << "MAIN UNIT TESTING - VALUE INSERTED: " << fill->data << endl;
    }
  }

  bstNode* mainRoot = bst.getRoot();
  bst.printPreorder(mainRoot);
  cout << endl;
  cout << endl;

  bst.deleteNode(8);
  bst.deleteNode(9);

  cout << "UNIT TESTING - TREE OUT AFTER DOUBLE ROOT DELETION : " << endl;
  cout << endl;

  mainRoot = bst.getRoot();
  bst.printPreorder(mainRoot);
  cout << endl;
  cout << endl;

  return 0;
}