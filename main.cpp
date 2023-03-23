#include "main.h"

using namespace std;

int main( int argc, const char* argv[] )
{
  string inputFile;

  //inputFile = argv[1];

  string dummyplugFile = "p3_test4.txt";
  string line;

  BinarySearchTree bst;

  cout << endl;
  
  ifstream portal1( dummyplugFile );
  int value;

  while( portal1 >> value )
  {
    cout << value << endl;
    bst.insert(value);
  }

  

  while( portal1 >> value )
  {
    cout << "TARGET = " << value << ", FOUND = " << bst.search(value) << endl;
  }
  
  cout << "FIRST STATE - BINARY SEARCH TREE STRUCTURE OUTPUT: " << endl;
  cout << endl;

  bstNode* mainRoot = bst.getRoot();
  bst.printPreorder(mainRoot);
  cout << endl;
  cout << endl;

  portal1.close();

  return 0;
}