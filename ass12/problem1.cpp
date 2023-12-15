#include <iostream>
#include<vector>
#include<list>


// I got inspired by: https://www.techiedelight.com/longest-increasing-subsequence-using-dynamic-programming/
// where I also find an O(n.lg n), but it will not satisfy the testcase


/*
Solving this problem via dynamic programming requires the problem to satisfy two propreties
1) OPTIMAL SUBSTRUCTURE: an optimal solution to a problem contains optimal solution to subproblems
2) OVERLAPPING PROBLEMS: we can find a recursive formula to find an optimal solution to the problem where many subproblems
                         are repeatedly computed

After checking those two propreties, we can solve the problem in two manners: a top-down approach (memorization)
or a "bottom-up" approach

I will use the second method in my computation where we first solve smaller subproblems, then use them to solve bigger subproblems

The idea of the algorithm works as follow:
  => Let arr[0..n] be the input array
	=> for each 0<=i<n, we compute LIS[i], which is the max orderes subarray of subproblem arr[0..i], ending with element arr[i]
	=> to calculate LIS[i], we consider LIS of all smaller values than i, noted j, already computed and pick the max lenghted LIS[j]
	for which arr[j] < arr[i]

NB: this algorithm will only give the lenghth of the Max ordered subarray, to get the actual LIS, instead of holding the lenghth
    I created an array of vectors, each vector contain solution of a subproblem
		based on the optimal substructure proprety, LIS[i], will contain optimal solution of subproblem arr[0..i-1] ending in arr[i]
		hence LIS[n] will contain solution of the whole problem consisting of arr[0..1-n] ending at arr[n].

NB: Complexity will be O(n^2) because of the nested loops.
*/


using namespace std;



void findLIS(int arr[], int n) { //function that prints Max ordered subarray noted LIS
	vector<int> LIS[n]; //we create an array of vectors to store the different LIS, gathered from solving subproblems
	LIS[0].push_back(arr[0]); //initialize the first vector with the first element of array, the first vector will contain only one elem
	for (int i= 1; i<n; i++) //loop through all vectors inside the array
	{
		for (int j=1; j<i; j++) //for each element in subarray arr[1..n]
		{
			if (arr[j] < arr[i] && LIS[j].size() > LIS[i].size()) //condition of the algorithm
			{
				LIS[i] = LIS[j]; //make the vector at the current index equal to the vector on index j
			}
		}
		LIS[i].push_back(arr[i]); //add the value arr[i], to the last vector in the array (Lis[i])
	}
	int max_lenght=0;
    for (int i = 0; i < n; i++) //loop through all vectors in our array and pick the one with the highest size
    {
        if (LIS[max_lenght].size() < LIS[i].size()) {
            max_lenght = i;
        }
    }
		for(vector<int>::iterator it = LIS[max_lenght].begin();it!=LIS[max_lenght].end(); it++)  //using iterator to print value of vector with largest lenghth
		{
      cout << *it << " ";
    }
		cout << endl;
}



int main()
{
	int arr[] = {8, 3, 6, 50, 10, 8, 100, 30, 60, 40, 80};
	int n = sizeof(arr)/sizeof(arr[0]);
	cout << "Sample input" << endl;
	for (int i=0; i<n; i++)
	{
		cout << arr[i] << " ";
	}
	cout << endl;
  cout << "Sample output" << endl;
	findLIS(arr, n);
}
