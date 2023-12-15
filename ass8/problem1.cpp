#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

//our sorting funtion, it returns the sorted vector and take the unsorted vector
 vector<int> countSort(vector<int>& vec) {
  vector<int> output; //declaring vector that will hold the sorted sequence
  vector<int> C; //declaring the counting array to hold the count
  int range = 10; //declaring the range

  output.assign(vec.size(), 0); //initializing size of output vector as size of initial vector
  C.assign(range, 0); //filling elements of C with 0

//loop to assign to each elem of C, the number of occurnance of index value present in original vector
  for (int j=0; j<vec.size()-1; j++)
  C[vec[j]] = C[vec[j]] + 1;

//updating C such that each at each index, we store number of elements in non-sorted vector smaller or equal than index
  for (int i=1; i<=C.size()-1; i++)
  C[i] = C[i] + C[i-1];

//placing at each iteration elements in their right place in "output" vector with reducing C at each iteration
  for (int j=output.size()-1; j>=0; --j) {
    output[C[vec[j]]] = vec[j];
    C[vec[j]] = C[vec[j]] - 1;
  }
return output; //return the sorted vector
}

//function implementing bucket sort
vector<float> bucketsort(vector<float>& vec, int n) {

  //all elements are in range [0, 1) so no normalization is required
  //creat n buckets
  vector<float> buckets[n];
  //insert elements of vec in different buckets
  for (int i = 0; i < n; i++) {
        int bucket_index = n * vec[i]; // Index in bucket
        buckets[bucket_index].push_back(vec[i]);
    }
  //sorting elements inside each bucket using sorti algorithm
  for (int i = 0; i < n; i++)
        sort(buckets[i].begin(), buckets[i].end());

  //concatenating all sorted buckets to get the sorted version of the original array
  int index = 0;
  for (int i = 0; i < n; i++)
        for (int j = 0; j < buckets[i].size(); j++)
              vec[index++] = buckets[i][j];
  return vec;
}

//function implementing bubble sort to sort the strings
//idea: swap elements next to each other when comparing them alphabetically bases on ASCII table
//if we concider k as constant, time complexity of the alg is O(n) in average case scenario
void stringsort(vector<string>& vec, int n)
{
    string temp;
    int j = 0;
	  bool swap = true;

    while (swap){
		swap = false;
		j++;
		for (int l = 0; l < n - j; l++) {
      //swap only if condition is satisfied
			if (vec[l] > vec[l + 1]) {
				temp = vec[l];
				vec[l] = vec[l + 1];
				vec[l + 1] = temp;
				swap = true;
			}
		}
	}
}

int main () {
 vector<int> vec1;
 vec1.insert(vec1.begin(), 1);
 vec1.insert(vec1.begin(), 2);
 vec1.insert(vec1.begin(), 6);
 vec1.insert(vec1.begin(), 7);
 vec1.insert(vec1.begin(), 6);
 vec1.insert(vec1.begin(), 1);
 vec1.insert(vec1.begin(), 9);

 cout << "non sorted elements are :" << endl;
 for (int i=0; i<vec1.size(); i++)
 cout << vec1[i] << " ";
 cout << endl;

 vec1 = countSort(vec1);

 cout << "sorted elements are :" << endl;
 for (int i=0; i<vec1.size(); i++)
 cout << vec1[i] << " ";
 cout << endl;


 vector<float> vec2;
 vec2.insert(vec2.begin(), 0.1);
 vec2.insert(vec2.begin(), 0.3);
 vec2.insert(vec2.begin(), 0.6);
 vec2.insert(vec2.begin(), 0.7);
 vec2.insert(vec2.begin(), 0.6);
 vec2.insert(vec2.begin(), 0.1);
 vec2.insert(vec2.begin(), 0.9);

 cout << "non sorted elements are :" << endl;
 for (int i=0; i<vec2.size(); i++)
 cout << vec2[i] << " ";
 cout << endl;

 vec2 = bucketsort(vec2, 7);

 cout << "sorted elements are :" << endl;
 for (int i=0; i<vec2.size(); i++)
 cout << vec2[i] << " ";
 cout << endl;


 vector<std::string> vec3 {"word", "category", "cat", "new", "news", "world", "bear", "at", "work", "time"};
 cout << "non-sorted elements are :" << endl;
 for (int i=0; i<vec3.size(); i++)
 cout << vec3[i] << " ";
 cout << endl;

 stringsort(vec3, 10);

 cout << "sorted elements are :" << endl;
 for (int i=0; i<vec3.size(); i++)
 cout << vec3[i] << " ";
 cout << endl;





}
