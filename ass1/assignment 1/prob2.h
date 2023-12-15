#include <iostream>
//our class definition
template <class T>
class Stack {
protected:
  T* ptr;
  int idx; //num of elem in the array
  int last; //last non free position
public:
  Stack (); //constructor
  ~Stack ();//destructor
  Stack(const Stack&);//copy constructor
  Stack (int size_);//size setter

  bool push(T elem); //adds elements
  bool pop(T& out); //pops out elements
  T back(void);//return an object to the top of the stack
  int getentries();//number of entries


};
