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
    if( slot == '\n' )
    {
      portal1.ignore(1);
      cout << "IGNORING YOU" << endl;
    }
    else if( slot == '$' )
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
      cout << "VALUE = " << value << endl;
      bst.insert(value);
    }
  }

/*
  bool notInt = true;

  while( notInt )
  {
    if( portal1.peek() == '\n' || portal1.peek() == '$' )
    {
      portal1.ignore(1,'$');
      cout << "IGNORING YOU" << endl;
    }
    else
  }
*/
  while( portal1 >> slot )
  {
    if( slot == '\n' )
    {
      portal1.ignore(1);
      cout << "IGNORING YOU" << endl;
    }
    else if( slot == '$' )
    {
      break;
    }
    else if( isdigit(slot) )
    {
      cout << "GOT A SEARCH, PAW" << endl;
      string s(1, slot);
      value = stoi(s);
      cout << "VALUE = " << value << endl;
      bst.search(value);
    }
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