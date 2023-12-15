/*
Mahdi Ouchrahou
m.ouchrahou@jacobs-university.de
Assignment 2 problem 4
*/
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main () {
  vector<int> A; //declaring our vector
  for(int i = 30; i >=1; i--)  //inserting elements from 1 to 30
		A.push_back(i);

  A.push_back(5); //adding 5 to the end
  reverse(A.begin(), A.end());//using reverse to revers our vector
  vector<int>::const_iterator it;//declaring iterator
  for (it = A.begin(); it != A.end(); ++it)//printing our vector
    cout << *it << " ";
  replace(A.begin(), A.end(), 5, 129); //replacing each 5 in the vector by 129
  cout << endl;
  for (it = A.begin(); it != A.end(); ++it)//printing our vector
    cout << *it << " ";
  cout << endl;


return 0;

}
