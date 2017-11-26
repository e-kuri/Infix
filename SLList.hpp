#ifndef SLLIST_H
#define SLLIST_H

#include<iostream>

using namespace std;

template <typename T>  class SLList;
template <typename T>
ostream &  operator << (ostream &,  SLList <T> &);


template <typename T>
struct Node{
  T info;
  Node* next;
};

template <typename T>
class SLList  {

protected:
  Node<T> * head;
  Node<T> * tail;
  int nNodes;


 public:
  SLList();
  ~SLList();
  bool isEmpty();
  bool insertHead(const T&);
  bool insertTail(const T&);
  bool removeHead(T&);
  bool removeTail(T&);
  Node<T>* getHead(){return head;}
  Node<T>* getTail(){return tail;}
  
  friend ostream &  operator << <>(ostream &,  SLList <T> &);
 
};

#include "SLList.cpp"

#endif
