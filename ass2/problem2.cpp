/*
Mahdi Ouchrahou
m.ouchrahou@jacobs-university.de
Assignment 2 problem 2
*/
#include <iostream>
#include <deque>

using namespace std;

int main () {
  deque<float> A;//declaring our deque
  float x;
  //infinite loop to enter floats
  while (1) {
    cin >> x;
    if (x==0) break;//stop if element is 0
    else if (x<0) A.push_front(x); //append at the begining of A if x<0
    else if (x>0) A.push_back(x);//append at the end of A
  }
  int i;
  //printing in the screen elements of our deque using overloaded [] operator
  for (i = 0; i < A.size(); i++)
		cout << A[i] << " ";

    cout << endl;
    //declaring an iterator
    deque<float>::const_iterator it;
    int count=0; //using a count var to get the position of the first positive integer in the queu
    for (it = A.begin(); it != --A.end(); it++){//looping through all element
      count++; //contains position of 1st positive elem
        if (*it>0) break;
    }
    it = A.begin() + (count-1); //initializing iterator to insert 0
    it = A.insert (it,0); //insert the 0 at the position of iterator
    for (i = 0; i < A.size(); i++) //print elem of queeu
  		cout << A[i] << " ";


}
