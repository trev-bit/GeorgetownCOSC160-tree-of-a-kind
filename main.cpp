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
      bst.insert(value);
      // cout << "MAIN UNIT TESTING - VALUE INSERTED: " << fill->data << endl;
    }
  }

  bstNode* mainRoot = bst.getRoot();

  bst.printPreorder(mainRoot);

  cout << "UNIT TESTING - BOOL PRESENCE OF #13 = " << bst.search(13);

  return 0;
}