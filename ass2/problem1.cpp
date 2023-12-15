/*
Mahdi Ouchrahou
m.ouchrahou@jacobs-university.de
assignment 2 problem 1
*/
#include <iostream>
#include <list>
#include <cstdio>
#include <fstream>

using namespace std;



int main () {
  //declaring both lists A and B
  list<int> A;
  list<int> B;
  int x;
  //cout << "enter pos element : " << endl;
  while (1) {
   cin >> x;
   if (x>0) {
     //adding positive element to the
     A.push_back(x);
     B.push_front(x);
   }
   else break;
  }
  //cout << " our list A : " <<endl;
  list<int>::const_iterator it;
  for (it = A.begin(); it != A.end(); ++it)
    cout << *it << " ";
//cout << "our list B" << endl;

  FILE* ptr = fopen("listB.txt" , "w");
  for (it = B.begin(); it!=B.end(); ++it)
  fprintf(ptr, "%d ", *it);

 cout << endl;

 A.splice(A.end(), A, A.begin());

 B.splice(B.end(), B, B.begin());


 for (it = A.begin(); it!= (--(A.end())); it++) {
   cout << *it << ", ";
 }
 it = A.end();
 cout<< *it;
 cout <<endl;
 for (it = B.begin(); it!= (--(B.end())); it++) {
   cout << *it << ", ";
 }
 it = B.end();
 cout<< *it;

 cout << endl;

 A.merge(B);

 A.sort();

 for (it = A.begin(); it!=A.end(); ++it) {
   cout << *it << " ";
 }







}
