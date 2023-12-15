#include <iostream>
#include <vector>

using namespace std;

//we will implement radixsort using bucket sort algorithm as a stable algorithm to sort digits
void bucketsort(vector<int>& vec, int exp)
{
//base case
    if (exp == 0) {
        return;
    }
    else {
        vector<int> buckets[10];
        for (int i = 0; i < vec.size(); i++) {
            int bucketindex = (vec[i] / exp) % 10;
            buckets[bucketindex].push_back(vec[i]);
        }
        for (int i = 0; i < 10; i++) {
            if (buckets[i].size() > 1) {
                bucketsort(buckets[i], exp / 10);
            }
        }
        int index = 0;
        for (int i = 0; i < 10; i++) {
            for (int j = 0; j < buckets[i].size(); j++) {
                vec[index++] = buckets[i][j];
            }
        }
    }
}

void radixsort(vector<int>& vec)
{
//finding max element of vector
    int maxvector = vec[0];
    for (int i = 1; i <= vec.size(); i++) {
        if (vec[0] < vec[i]) {
            maxvector = vec[i];
        }
    }
    int exp = 1;
    while (maxvector / exp > 10) { //applying the formula
        exp *= 10;
    }

    bucketsort(vec, exp); //calling bucket sort 
}


int main () {
  vector<int> vec;

  vec.insert(vec.begin(), 75);
  vec.insert(vec.begin(), 2441);
  vec.insert(vec.begin(), 648);
  vec.insert(vec.begin(), 746);
  vec.insert(vec.begin(), 6785);
  vec.insert(vec.begin(), 1452);
  vec.insert(vec.begin(), 9992);
  cout << "non sorted elements are :" << endl;
  for (int i=0; i<vec.size(); i++)
  cout << vec[i] << " ";
  cout << endl;
  radixsort(vec);
  cout << "sorted elements are :" << endl;
  for (int i=0; i<vec.size(); i++)
  cout << vec[i] << " ";
  cout << endl;


}
