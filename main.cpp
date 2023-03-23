#include "main.h"


int main( int argc, const char* argv[] )
{
  string inputFile;

  //inputFile = argv[1];

  string dummyplugFile = "p3_test4.txt";

  BinarySearchTree bst;

  cout << endl;
  
  ifstream portal1( dummyplugFile );
  char slot;
  string one;
  int value;
  char fill;


  while( portal1 >> slot)
  {
    if( slot == '$' )
    {
      break;
    }
    else if( isdigit(slot) )
    {
      one = slot;

      fill = portal1.peek();

      while( isdigit(fill) )
      {
        portal1 >> fill;
        one = one + fill;
        fill = portal1.peek();
      }

      value = stoi(one);
      bst.insert(value);
    }
  }

  cout << "FIRST STATE - BINARY SEARCH TREE STRUCTURE OUTPUT: " << endl;
  cout << endl;

  bstNode* mainRoot = bst.getRoot();
  bst.printPreorder(mainRoot);
  cout << endl;
  cout << endl;

  while( portal1 >> slot )
  {
    if( slot == '$' )
    {
      break;
    }
    else if( isdigit(slot) )
    {
      one = slot;

      fill = portal1.peek();

      while( isdigit(fill) )
      {
        portal1 >> fill;
        one = one + fill;
        fill = portal1.peek();
      }

      value = stoi(one);
      if( bst.search(value) )
      {
        cout << value << " LOCATED." << endl;
      }
      else
      {
        cout << value << " NOT FOUND." << endl;
      }
    }
  }
  

  portal1.close();

  return 0;
}