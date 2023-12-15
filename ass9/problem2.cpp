/*
Mahdi Ouchrahou
m.ouchrahou@jacobs-university.de
hw 9
*/


//   ** PROBLEM 2 : **
// ** A) **
// In this exercice we can use two approaches, one using recursion and one using iteration and 3 pointers
// I will implement the first approach
// It consist of deviding the linked list into two parts: the head and the rest of the list with n-1 elements
// the idea is to recursively reverse the second part of the linked list then putting the head of the initial list in the last position
// At the end we return the head of the second part (n-1) elements as being the new head of our reversed list
// I will put the pseudocode in an attached pdf and implement it in this code to check its correctness
// The algorithm will run in O(n) time complexity since it will traverse all elements of the list
// and since it does not use any extra helper storage it is an in-situ algorithm

// ** B) **
// See implementation in this code, I have first implemented a binary tree, then convert it to a linked list using the declared function of
// our linked list from the last question.
// time complexity will be O(n-1) since our convert algorithm go through all elements in the right and in the left of the root,
// but by definition the root is in the correct place, since the tree contains n elements including root, time complexity would be O(n-1)

// ** C) **

#include <iostream>
#include <string>

using namespace std;

struct Node {
  int data;
  Node* next;
};

class LinkedList {
public:
  Node *head, *tail;


  LinkedList() { //constructor
    head = NULL;
    tail = NULL ;
  }
  void CreateNode (int x) {
    Node *temp = new Node;
    temp-> data = x;
    temp -> next = NULL;
    if (head==NULL) {
      head = temp;
      tail = temp;
      temp=NULL;
    }
    else {
      tail->next = temp;
      tail = temp;
    }
  }

  void display () {
    Node *temp = new Node;
    temp = head;
    while (temp!=NULL) {
      cout << temp->data << endl;
      temp = temp->next;
    }
  }

  void push(int data)
    {
        Node *newel = new Node;
        newel->data = data;
        newel->next = head;
        head=newel;
    }

  Node* reverse (Node* head) { //function to reverse a linked list
    if (head == NULL || head->next == NULL ) return head; //check if list is empty or contains only one element
    Node* rest = reverse(head->next); //recursively reverse the second part of the list such that the head of the second part of the list is the last element
    (head->next)->next = head; //put the head of the original list in his right place (end of second part of the list)
    head->next = NULL; //update next of head to point to null as its the new last element
    return rest;//update the head pointer when calling the function
    free(rest);
  }

};


class binarytree { //we create a Binary search tree class
public://made everything public to avoid errors
  class node { //the tree class contains a class for each node
  public: //made everything public to avoid errors
    int data; //it has data
    node* right; //three  pointers
    node* left;
    node* parent;
    node (int data) { //constructor of the node class
      this->data = data;
      this->right = NULL;
      this->left = NULL;
    }
  };
  node* root; // tree have a root

  void insert(node* root, int data) { //function that insert a given elements, starting from the root, in its correct place of the tree
    if (data <= root->data) { //check for left side
      if (root->left == NULL) {
        node *newelem = new node(data);
        root->left = newelem;
      }
      else {
        insert(root->left, data); //recursivelly insert
      }
    }
    else if (data >= root->data) { //check for right side
      if (root->right == NULL) {
        node* newelem = new node(data);
        root->right = newelem;
      }
      else {
        insert(root->right, data); //recursively insert
      }
    }

  }

  void convert (LinkedList& list, node* root) { //this function converts a tree to a linked list
    if (root->left != NULL) { //left part first, starting from most left (smallest element)
      convert(list, root->left);
    }
    list.push(root->data); //pushing element
    if (root->right != NULL) { //then right part untill most right element
      convert(list, root->right);
    }

  }

  binarytree () { //tree class constructor
    this->root = NULL;
  }

  void insertintree(int data) { //insert element in tree
    if (this->root == NULL) { //check for empty tree
      node *newel =new node(data);
      this->root=newel;
      return;
    }
    insert(this->root, data); //use insert function to insert in the right position

  }
  void converttolinkedlist (LinkedList& list) { //function that converts to a linked list
    convert(list, this->root); //use the convert helper function
  }
};





int main () {
  LinkedList list1;
	list1.CreateNode(25);
	list1.CreateNode(50);
	list1.CreateNode(90);
	list1.CreateNode(40);
  list1.CreateNode(70);
  list1.CreateNode(80);
  list1.CreateNode(100);
  cout << "non reversed list" << endl;
  list1.display();
  list1.head = list1.reverse(list1.head);
  cout << " reversed list" << endl;
  list1.display();
  cout << endl << endl;

  binarytree tree1;
  tree1.insertintree(1);
  tree1.insertintree(42);
  tree1.insertintree(9);
  tree1.insertintree(2);
  LinkedList list2;
  tree1.converttolinkedlist(list2);
  list2.head = list2.reverse(list2.head);  //comment this to get ascending order
                       //if you leave it uncommented you will get the elements in descending order
  list2.display();

  return 0;
}
