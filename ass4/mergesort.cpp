/*
Mahdi Ouchrahou
m.ouchrahou@jacobs-university.de
assignment 4
*/

#include <iostream>
#include <chrono>
#include <fstream>
using namespace std;
using namespace std::chrono;

void merge(int arr[], int l, int m, int r) //merge function
{
    int i, j, k;
    int leftarr = m - l + 1;
    int rightarr = r - m;

    int L[leftarr], R[rightarr]; //declaring our two splitted arrays

    //filling both arrays L and R
    for (i = 0; i < leftarr; i++)
        L[i] = arr[l + i];
    for (j = 0; j < rightarr; j++)
        R[j] = arr[m + 1 + j];

    i = 0;
    j = 0;
    k = l;

    while (i < leftarr && j < rightarr)
    {
        if (L[i] <= R[j])
        {
            arr[k++] = L[i++];
        }
        else
        {
            arr[k++] = R[j++];
        }
    }

    while (i < leftarr)
    {
        arr[k++] = L[i++];
    }

    while (j < rightarr)
    {
        arr[k++] = R[j++];
    }
}

void insertionSort(int arr[], int l, int r) //insertion sort function
{
    int i, key, j;
    for (i = l + 1; i <= r; i++)
    {
        key = arr[i];
        j = i - 1;

        while (j >= l && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

void mergeSort(int arr[], int l, int r, int k) //merge sort function
{
    if ((r - l) <= k) //if size of subsequences less or equal to k, apply insertion
    {
        insertionSort(arr, l, r);
    }
    else
    {

        int m = (l + r) / 2;
        mergeSort(arr, l, m, k); //recursive call
        mergeSort(arr, m + 1, r, k);//recursive call
        merge(arr, l, m, r);//calling merge function to combine arrays
    }
}


int main()
{
    int size = 2000; //size of the array is 2000;
    int arr[size];
    //inserting our timing data into a file
    ofstream out;
    out.open("time.txt");


    for (int k = 0; k < size; k=k+10) //Incrementing the value of k with 10
    {

        //Best case scenario (sorted array)
        for (int i = 0; i < size; i++)
        {
            arr[i] = i;
        }

        auto start1 = high_resolution_clock::now();
        mergeSort(arr, 0, size - 1, k);
        auto stop1 = high_resolution_clock::now();
        auto best_case = duration_cast<microseconds>(stop1 - start1);

        //Average case scenario (random array)
        srand(time(NULL));
        for (int i = 0; i < size; i++)
        {
            arr[i] = rand() % size;
        }

        auto start2 = high_resolution_clock::now();
        mergeSort(arr, 0, size - 1, k);
        auto stop2 = high_resolution_clock::now();
        auto average_case = duration_cast<microseconds>(stop2 - start2);


        //Worst case scneario(descending order)

        for (int i = 0; i < size; i++)
        {
            arr[i] = size - i;
        }

        auto start = high_resolution_clock::now();
        mergeSort(arr, 0, size - 1, k);
        auto stop = high_resolution_clock::now();
        auto worst_case = duration_cast<microseconds>(stop - start);
//print data in column form
        out << k << " " << (double)worst_case.count() << " " << (double)best_case.count() << " " << (double)average_case.count() << endl;

    }
    return 0;
}
