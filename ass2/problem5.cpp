/*
Mahdi Ouchrahou
m.ouchrahou@jacobs-university.de
Assignment 2 problem 5
*/
#include <iostream>
#include <set>
#include <cstdlib>
#include <ctime>
#include <algorithm>


using namespace std;

   struct cmpStruct {
  bool operator () (int const& lhs, int const& rhs)
  {
    return lhs < rhs;
  }
};

int main()
{
    srand(time(NULL)); //initializing generator
    set<int, cmpStruct> lotto; //declaring container
    int random;
    while (lotto.size() < 6) //filling container
    {
        random = rand() % 49 + 1;
        lotto.insert(random);
    }

    set<int>::iterator it; //declaring iterator
    //loop to print element of our container using iterator
    for (it = lotto.begin(); it != lotto.end(); it++)
    {
        cout << *it << " ";

    }
    cout << endl;
    return 0;
}
