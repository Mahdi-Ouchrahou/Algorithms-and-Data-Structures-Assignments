#include <iostream>
#include <string>
#include "prob2.h"

using namespace std;

//constructor definition
template<class T>
Stack<T>::Stack() {
  ptr = new T[10];
  idx = 10;
  last = -1;
}
//destructor definition
template<class T>
Stack<T>::~Stack() {
  delete [] ptr;
}
//copy constructor
template<class T>
Stack<T>::Stack(const Stack&) {}

//push method implementation
template<class T>
bool Stack<T>::push(T elem) {
  if (last + 1 == idx) return false; //means that the stack is full
  else { //add elem to the stack
    last++;
    ptr[last] = elem;
    return true;
  }
}

//pop method implementation
template <class T>
bool Stack<T>::pop(T& out) {
  if(last<0) return false;
  else {
    out = ptr[last];
    last--;
    return true;
  }
}

template<class T>
T Stack<T>::back(void){
  return ptr[last++];
}

template<class T>
int Stack<T>::getentries() {
  return last+1;
}

int main () {
  int a;
  Stack<int> stackint;
  for(int j=0; j<10; j++) {
    cout << stackint.push(j) << endl;
    cout << stackint.pop(a) << endl;
    cout << stackint.back() << endl;
    cout << stackint.getentries() << endl;
  }
}
