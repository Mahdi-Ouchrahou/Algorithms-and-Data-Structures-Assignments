//   Mahdi Ouchrahou
//   m.ouchrahou@jacobs-universty.de
//  Homework 11, problem 11.1, b)


#include <iostream>

using namespace std;

//open adress using linear probing, select an h

//we assume our hash table has 7 number of positions
//lets use the hash function h(k) = k mod m (we pick m to be a fixed prime equal to the maxsize and k our key)

class Node
{
public:
  int key;
  int value; //value holded by key
  Node (int key, int value) // constructor of node
  {
    this->key = key;
    this->value = value;
  }
};

class HashTable
{
private:
  Node **arr; //hash table
  int maxsize; //max size of table choosen to be 7
  int currentsize; //current size of table

public:
  HashTable() //default constructor
  {
    maxsize = 7;
    currentsize = 0;
    arr = new Node*[maxsize];
    for (int i=0; i<maxsize; i++) //initializing all nodes to NULL before inserting anything
    {
      arr[i] = NULL;
    }
  }


  int hashCode(int key) //hash function
  {
    return key % maxsize;
  }


  void insertnode(int key, int value) //function to onsert
  {
    if (currentsize == maxsize)
    {
      cout << "overflow";
      return;
    }
    int j = hashCode(key); //first linear probe with i=0
    while (arr[j] != NULL) //repeat linear probing untill an empty index is found
    {
      j = (j+1) % maxsize;
    }
    arr[j] = new Node(key, value); //create the inserted node
    arr[j]->key = key; //assign its key
    arr[j]->value = value; //assign its value
    currentsize++; //add 1 to the current size since we added one element
  }


  int get(int key) //function to search
  {
    if (isEmpty() == true)
    {
      cout << "is empty";
      return -1;
    }
    int j = hashCode(key); //initial probe, i=0
    int temp = j; //auxilary variable to end loop
    while (true) //enter infinite loop
    {
      if (arr[j] == NULL) //probe again if a NULL position is found
      {
        j = (j+1) % maxsize;
      }
      else if (arr[j]->key != key)//probe again if key do not match
      {
        j = (j+1) % maxsize;
      }
      else
      {
    //    cout <<"not found";
        break;
      }//else, end probing

      if (j==temp) { //case where table contains only one element
        temp = -1;
        break;
      }
    }

    if (temp == -1)
    {
      cout << "not found" << endl;
      return -1;
    }

    else return arr[j]->value;
}






  bool isEmpty() //functio to tell if empty
  {
    if (this->currentsize == 0)
    {
      return true;
    }
    else return false;
  }

  void display()
  {
    for (int i =0; i<maxsize; i++)
    {
      if (arr[i] != NULL)
      {
        cout << "index in hash table [" << i << "] : key-> " << arr[i]->key << " value -> " << arr[i]->value << endl;
      }
    //  cout << "--->" << arr[i]->value << endl;
    }
  }
};

int main() {
  HashTable arr;

  arr.insertnode(4445, 22);
  arr.insertnode(4413, 77);
  arr.insertnode(4418, 55);
  arr.insertnode(4474, 77);

  arr.display();

   cout << "value of key 4418 is : " << arr.get(4418) << endl;
   cout << "value of key 44 is : " << arr.get(44) << endl;
}
