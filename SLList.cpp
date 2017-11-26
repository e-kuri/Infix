template<typename T>
SLList<T>::SLList(){head = tail = 0; nNodes = 0;}

template <typename T>
SLList<T>::~SLList()
{
  if(!isEmpty())
    {
      Node<T> * temp1 = head;
      Node<T> * temp2;
      while(temp1 != 0){
        temp2 = temp1;
        temp1 = temp1 -> next;
        delete temp2;
      }
      head = tail = 0;
      
    }
}

template<typename T>
bool SLList<T>::insertHead(const T& info)
{
  Node<T> * nnode = new Node<T>;
  if(nnode != 0){
    nnode -> info = info;
    if(isEmpty()){
      head = tail = nnode;
      head -> next = 0;
    }
    else{
      nnode -> next = head;
      head = nnode;
    }
    nNodes++;
    return true;
  }
  return false;
}

template<typename T>
bool SLList<T>::removeHead(T& infor){

  if(!isEmpty()){
    Node<T> * temp = head;
    infor =  head ->info;
    if(head == tail)
      head = tail = 0;
    else
      head = temp -> next;
    delete temp;
    return true;
  }
  return false;
}



template<typename T>
bool SLList<T>::removeTail(T& infor){

  if(!isEmpty()){
    Node<T> * temp = tail;
    infor =  tail -> info;
    if(head == tail)
      head = tail = 0;
    else{
      Node<T> * temp2 = head;
      while(temp2 -> next != tail)
        temp2 = temp2 -> next;
      tail = temp2;
    }
    delete temp;
    return true;
  }
  return false;
}



template<typename T>
bool SLList<T>::isEmpty(void){
  return head == 0;
}

template<typename T>
bool SLList<T>::insertTail(const T& info)
{
   Node<T> * nnode = new Node<T>;
      if(nnode != 0){
	nnode -> info = info;
	if(isEmpty()){
	  head = tail = nnode;
	  head -> next = 0;
	}
	else{
	  nnode -> next = tail -> next;
	  tail -> next = nnode;
	  tail = nnode;
	}
	nNodes++;
	return true;
      }
      return false;
      
}

template<typename T>
ostream & operator <<   (ostream & sal, SLList<T> & lista)
{
  if(lista.head != 0){
    //    sal << "Lista Simplemente Ligada:" << endl;
    for(Node<T>* node = lista.head; node != 0; node = node -> next)
      sal << node -> info<<" ";
  }
  // else sal << "Lista vacia" ;
  return sal;
}

