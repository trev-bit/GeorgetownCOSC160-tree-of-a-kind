#include "main.h"


int main( int argc, const char* argv[] )
{
  string inputFile;
  //inputFile = argv[1];

  SplayTree plasma(9);

  cout << "MAKEFILE TEST - EXPECTED 9: " << plasma.getTest() << endl;

  cout << endl;


/*


  BinarySearchTree bst;

  cout << endl;
  
  ifstream portal1( inputFile );
  char slot;
  string one;
  int value;
  char fill;

  auto bstStart = std::chrono::high_resolution_clock::now();

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

  cout << "FIRST STATE - BINARY SEARCH TREE STRUCTURE OUTPUT BELOW: " << endl;
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
      bst.search(value);
    }
  }


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

      
      bst.deleteNode(value);
    }
  }
    portal1.close();


  cout << "FINAL STATE - BINARY SEARCH TREE STRUCTURAL OUTPUT BELOW: " << endl;
  cout << endl;

  auto bstEnd = std::chrono::high_resolution_clock::now();

  mainRoot = bst.getRoot();
  bst.printPreorder(mainRoot);
  cout << endl;
  cout << endl;


  auto bstTime = std::chrono::duration_cast<std::chrono::nanoseconds>(bstEnd - bstStart);

  cout << "BST TRAVERSALS:  " << bst.getTraversalCount() << endl;
  cout << "ELAPSED TIME:" << bstTime.count() << "nns" << endl;
  cout << endl;

  */

  return 0;
}