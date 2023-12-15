/*
Mahdi Ouchrahou
m.ouchrahou@jacobs-university.de
hw 9
*/

// time complexity of the algorithm is O(n)
#include <iostream>
#include <string>

using namespace std;

class binarytree;
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
  void converttotree(binarytree &tree, int start, int end); //function to be used before its definition
  void converttobinarytree(binarytree &tree)
    {
        struct Node *temp = this->head;
        int count = 0;
        while (temp->next != NULL)
        {
            temp = temp->next;
            count++;
        }
        converttotree(tree, 0, count);
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

  void helperprint(node *root)
    {
        if (root->left != NULL)
        {
            helperprint(root->left);
        }
        cout << root->data << " ";
        if (root->right != NULL)
        {
            helperprint(root->right);
        }
      }

    void print()
    {
        helperprint(this->root);
        cout<<endl;
    }


};

void LinkedList::converttotree(binarytree &tree, int start, int end)
{
    if (start > end)
    {
        return;
    }
    int mid = (start + end) / 2;
    struct Node *temp = head;
    int i = 0;
    while (i < mid && temp->next != NULL)
    {
        temp = temp->next;
        i++;
    }
    tree.insertintree(temp->data);
    converttotree(tree, start, mid - 1);
    converttotree(tree, mid + 1, end);
}

int main(){

    binarytree tree;
    LinkedList list1;
    list1.push(75);
    list1.push(999);
    list1.push(441);
    list1.push(7);
    list1.head = list1.reverse(list1.head);   //to have then in appropriate order
    cout << "linked list" <<endl;
    list1.display();

    list1.converttobinarytree(tree);
    cout << "binary tree " <<endl;
    tree.print();
    return 0;
}
