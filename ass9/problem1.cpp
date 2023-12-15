/*
Mahdi Ouchrahou
m.ouchrahou@jacobs-university.de
hw 9
*/



//   ** PROBLEM 1 : **
// ** A) **
//  see implementation

// ** B) **
// for the time complexity, no loop or iteration is used by the operations so they all have a complexity of O(1), except for the "display"
// function since it iterate through all elements of our stack, its complexity is O(n), with n size of the current size of the code

// ** C) **
//see implementation





#include <iostream>
#include <string>

using namespace std;


template <class T>
class stack { //declaring out class
   private:
     struct stacknode { //linked list implementation
       T data;
       stacknode* next;
     };

     int size;  //-1 if no size was passed
     int current_size; //unused ifsize=-1

   public:
     stacknode* top; //return top of the stack
     stack(int new_size) { //constructor
       this -> size = new_size;
       this -> current_size = 0;
       this -> top = NULL;
     }

     stack() { //default constructor
       this -> size = -1;
       this -> current_size = 0;
       this -> top = NULL;
     }


     void push(T x) { //push function
       if (this -> current_size == this -> size) { //throw exception
         cout << "stack overflow" << endl;
         exit(1);
       }
       stacknode* newelem = new stacknode;
       newelem->data = x;
       if (this->top == NULL){
         this->top = newelem;
         newelem->next = NULL;
         this->current_size++;
         return;
       }
       else {
         newelem->next=this->top;
         this->top = newelem;
         this->current_size++;
       }

     }


    T pop() { //pop function

      if (this -> current_size == 0) { //throw exception
        cout << "stack underflow" << endl;
        exit(1);
      }
      else {
        stacknode* temp = this->top;
        T data = temp->data;
        this -> top = temp ->  next;
      //  this -> next = NULL;
      delete temp;
      this -> current_size--;
      return data;
      }
    }  //return element or underflow error

     bool isEmpty() { //check if stack is empty
       if (current_size == 0) {
        // cout << "stackunderflow" << endl;
         return true;
       }
       else return false;
     } //return true if stack empty




     void display () { //print function
       if (current_size == 0) { //check for underflow
         cout << "stack underflow" << endl;
         exit(1);
       }
       else {
         stacknode* temp = this -> top;
         while (temp != NULL) {
           cout << temp->data << endl;
           temp = temp->next;
         }
       }

}

};

//template queue class
template<class T>
class queue {
private:
  stack<T> s1, s2; //constructed with two stacks
  int size; //keep track of the size of the queue
public:
  queue() { //const
    size=0;
  }

  void enqueue (T x) { //function that alligne elements in the correct order in stack s1 using stack s2
    //equivalent to a push operation
    while (!s1.isEmpty()) {
      T temp = s1.pop();
      s2.push(temp);
    //  s1.pop();
    }
    s1.push(x);
    while (!s2.isEmpty()) {
      T temp1 = s2.pop();
      s1.push(temp1);
    //  s2.pop();
    }
    this -> size++; //update size

}

T dequeue () { //equivalent to a pop operation, it pops the top of the stack s1 after it is modified by enqueue
  if (s1.isEmpty()==true) {
    cout << "queueu is empty" << endl;
    exit(0);
  }
  else {
    T delelem = s1.pop();
  //  s1.pop();
    this->size--;
    return delelem;
  }
}

void display1() { //function to print queueu
  s1.display(); //since s1 holds elements in correct order it is the one being printed
  cout << endl;
}
};



int main () {
  stack<int> Stack(5);
  //Stack.pop(); //if uncommented it will throw an error
  Stack.push(1);
  Stack.push(2);
  Stack.push(2);
  Stack.push(3);
  Stack.display();
  cout << endl;
  Stack.pop();
  Stack.display();
  cout << endl;
  Stack.pop();

  stack<string> Stack1(2); //using other data type
  Stack1.push("toto");
  Stack1.push("damso");
  Stack1.display();

  queue<double> Queue1;
  //Queue1.dequeue(); //if uncommented will throw error
  Queue1.enqueue(0.1);
  Queue1.enqueue(0.2);
  Queue1.enqueue(0.3);
  Queue1.enqueue(0.4);
  Queue1.enqueue(0.5);
  Queue1.display1();
  Queue1.dequeue();
  Queue1.dequeue();
  Queue1.display1();



  return 0;
}
