#include <iostream>
#include <cstdlib>

using namespace std;

class Complex {
  double r, i;
  public:
  //constructor
  Complex(double r, double i) {
    this->r = r;
    this->i = i;
  }

  //overloading operator "="
  Complex& operator= (const Complex z) {
    this->r = r;
    this->i = i;
    return *this;
  }

  //overloading operator "==" based on definition of two equal imaginary numbers
  bool operator== (const Complex& z) {
    if((r = r) && (i = i )) return true;
    else return false;
  }

  friend ostream& operator<< (ostream& z, Complex c) {
    z << c.r << "+" << c.i << "i" << endl;
    return z;
  }


};

//template function

template <typename T>
int arrsearch (T arr[], int s, T elem) {
  for(int i=0; i<=s; i++) {
    if (arr[i] == elem) return i;
  }
  return -1;
}

//our main function (test)

int main () {
  int arr1[]={1, 2, 3, 4, 5};
  int elem1=0;
  cout << "position of " << elem1 << "is "  << arrsearch(arr1, 5, elem1) << endl;

  float arr2[]={1.1, 2.2, 3.3, 4.4, 5.5};
  float elem2 = 1.1;
  cout << "position of " << elem2 << "is " << arrsearch(arr2, 5, elem2) << endl;

  string arr3[]={"aaaaa", "bbbb", "ccc", "dd", "e"};
  string elem3 = {"dd"};
  cout << "position of " << elem3 << "is " << arrsearch(arr3, 5, elem3) << endl;

  Complex arr4[] = {Complex(1, 0), Complex(0, 1), Complex(-1, -2)};
  
  cout << "position of searched elem is " << arrsearch(arr4, 3, Complex(0, 1)) << endl;





}
