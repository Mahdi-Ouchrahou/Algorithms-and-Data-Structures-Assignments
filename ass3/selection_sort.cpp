/*
Mahdi Ouchrahou
m.ouchrahou@jacobs-university.de
hw 3, prob 3.2
*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <ctime>
#//include <bits>

using namespace std;

//our selection sort functionl
void selection_sort(vector<int> arr, int size) {
  int key; //variable to hold index of the smallest element
  int i, j; //helping variables
  for (i=0; i<size-1; i++) {//first loop iterate from the first elem to the before last element
    //it is obvious that while sorting the last element will automatically be in the right position (biggest elem)
    key = i; //hold index of smallest elem

    for (j=i+1; j<size; j++) { //looping through the whole vector exept first elem
      if (arr[j] < arr[key]) { //if we found an elem that is smaller than the elem that we compare with
        key = j;//change indexes
      }
    }
    //swap elements to get the smallest one in the left sorted vector
    int temp = arr[key];
      arr[key] = arr[i];
      arr[i] = temp;
}


for (int x=0; x<size; x++){
  cout << arr[x] << " ";
}
cout << endl;
}
//here we declare a functor that will return a rendom value less that "max"
struct RandomGenerator {
  int maxValue;
  RandomGenerator(int max) :
          maxValue(max) {
  }
  int operator()() {
      return rand() % maxValue;
  }
};


int main () {
  vector<int> arr={4, 6, 2, 1, 5, 3};
  int i;
  cout << "initial vector  :\n";
  for (i=0; i<6; i++){
     cout << arr[i] << " ";
  }
  cout << endl;
  cout << "sorted vector : \n";

 selection_sort(arr, 6);
cout << endl;

int n;
cout << "enter num of elements to be randomly generated" << endl;
cin >> n;
vector<int> V(n); //declaring our vector of n random elements
//iterating through each element of the vector and assigning at each
//iteration a random number henerated by our functor
generate(V.begin(), V.end(), RandomGenerator(1000));
cout << "unsorted vector of random elements : " << endl;
for (i=0; i<n; i++){
   cout << V[i] << " ";
}
cout << endl;
cout << "sorted vector of n random numbers : \n";

selection_sort(V, n);
//here we considered the case b as if we are giving our selection sort
//a vector with the same elements
//no swap will be done in this case
cout << "case B: elements in the vector are all equal" << endl;
int x;
cout << "enter size of vector" << endl;
cin >> x;
vector<int> R(x, 10);//vector with x element all of value 10
cout << "initial vector in CASE B  :\n";
for (i=0; i<x; i++){
   cout << R[i] << " ";
}

cout << endl;
cout << "sorted array in CASE B, where no swap is done :" << endl;
selection_sort(R, x);

return 0;

}
