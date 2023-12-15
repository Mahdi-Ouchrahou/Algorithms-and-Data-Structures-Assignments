#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
#include <numeric>

using namespace std;

/*
To solve this problem we will use dynamic programming with a bottom-up approach
the idea is to start with the last row, starting from the first elem of that row, check for the max sum between this element and the two before him
loop trough all rows and the value contained at the root will be the maximum sum
I used another vector container to store at each time the chosen element

the code does not run..
*/

/*  b)
In the brute force approach, we would have computed all possible sums then pick the maximum sum over the total
This will require 2^n time complexity with n being the number of elements in our array (triangle)
Ideally, the algorithm I used will have a complexity of O(n.lg n) since it will choose, at each step, which sum to choose, this will reduce the amount of comparison and summation
number, hence complexity.
*/

/* c)
what would be the greedy choice ?
intuitively, we can come up with infinitly many suppositions for the greedy choice
the choice that makes more sens could be
 => in each raw, pick Max number between the left and the right child

To prove that this will not lead to a globally optimal solution we give a counter exemple:
consider the triangle
8
5 4
6 2 2 9
4 8 9 9 10

with our greedy supposition we would get as a final solution: 8 + 5 + 6 + 8 =27
However a globally optimal solution can be: 8 + 4 + 9 + 10 = 31

Hence, greedy algorithm will not work on this problem

*/



template <typename T>
std::vector<T> operator+(const std::vector<T>& a, const std::vector<T>& b)
{
    assert(a.size() == b.size());

    std::vector<T> result;
    result.reserve(a.size());

    std::transform(a.begin(), a.end(), b.begin(),
                   std::back_inserter(result), std::plus<T>());
    return result;
}


int maxSum(vector<vector<int> >& arr)
{

  int n = arr.size();
  vector<int> count (n);
  //I will store the sum and the choosen elements in a 2D vector


vector<vector<int>>::iterator row = arr.begin();


count[n] = arr[0][0];
 for (int i=arr.size(); i>=0; i--)
 {
   for (int j=0; j<=i+1; j++)
   {
     if (arr[i+1][j] > arr[i+1][j+1])
     {
       arr[i][j] = arr[i][j] + arr[i+1][j];

       count[i] = arr[i+1][j];
     }
     else
     {
       arr[i][j] = arr[i][j] + arr[i+1][j+1];
       count[i] = arr[i+1][j+1];
     }
   }

 }
return arr[0][0];
}




}








int main()
{
  vector<vector<int> > vec = {{7},  //I used a 2D vector to store the input triangle
                            {3,8},
                            {8,1,0},
                            {2,7,4,4},
                            {4, 5, 2, 6, 5}};
//  for (vector<int>::iterator it = )
  for (int i = 0; i < vec.size(); i++)
{
    for (int j = 0; j < vec[i].size(); j++)
    {
        cout << vec[i][j] << " ";
    }
    cout << endl;
}
int maxsum = maxSum(vec);
cout << maxsum << endl;



    return 0;
}
