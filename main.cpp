#include "main.h"


int main( int argc, const char* argv[] )
{
  string inputFile;
  inputFile = argv[1];

  /*



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

  BinarySearchTree unit_00;
  SplayTree unit_01;

  bstNode* rei = unit_00.getRoot();
  sNode* shinji = unit_01.getRoot();

  ifstream portal( inputFile );
  char slot;
  string one;
  int value;
  char fill;

  auto bstStart = std::chrono::high_resolution_clock::now();
  auto splayStart = std::chrono::high_resolution_clock::now();

  while( portal >> slot)
  {
    if( slot == '$' )
    {
      break;
    }
    else if( isdigit(slot) )
    {
      one = slot;

      fill = portal.peek();

      while( isdigit(fill) )
      {
        portal >> fill;
        one = one + fill;
        fill = portal.peek();
      }

      value = stoi(one);
      unit_00.insert(value);
      unit_01.insert(value);
    }
  }

  cout << "FIRST STATE - SPLAY TREE STRUCTURE OUTPUT BELOW: " << endl;
  cout << endl;

  rei = unit_00.getRoot();
  shinji = unit_01.getRoot();

  unit_00.printPreorder(rei);
  cout << endl;
  cout << endl;
  
  unit_01.printPreorder(shinji);
  cout << endl;
  cout << endl;

  while( portal >> slot )
  {
    if( slot == '$' )
    {
      break;
    }
    else if( isdigit(slot) )
    {
      one = slot;

      fill = portal.peek();

      while( isdigit(fill) )
      {
        portal >> fill;
        one = one + fill;
        fill = portal.peek();
      }

      value = stoi(one);
      unit_00.search(value);
      unit_01.search(value);
    }
  }

  while( portal >> slot )
  {
    if( slot == '$' )
    {
      break;
    }
    else if( isdigit(slot) )
    {
      one = slot;

      fill = portal.peek();

      while( isdigit(fill) )
      {
        portal >> fill;
        one = one + fill;
        fill = portal.peek();
      }

      value = stoi(one);
      unit_00.deleteNode(value);
      unit_01.deleteNode(value);
    }
  }

  portal.close();

  cout << "FINAL STATE - BINARY SEARCH TREE STRUCTURAL OUTPUT BELOW: " << endl;
  cout << endl;

  auto bstEnd = std::chrono::high_resolution_clock::now();
  auto splayEnd = std::chrono::high_resolution_clock::now();

  rei = unit_00.getRoot();
  shinji = unit_01.getRoot();

  unit_00.printPreorder(rei);
  cout << endl;
  cout << endl;

  unit_01.printPreorder(shinji);
  cout << endl;
  cout << endl;


  return 0;
}