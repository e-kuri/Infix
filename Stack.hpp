#include "SLList.hpp"
template <class T>
class Stack : public SLList<T>{
public:
  T&   top(){return SLList<T>::getHead()->info;}
  bool push(const T& info){return SLList<T>::insertHead(info);}
  bool pop(T& info){return SLList<T>::removeHead(info);}
 
};

