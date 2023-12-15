#include <iostream>


using namespace std;

enum Color {RED, BLACK};

struct Node
{
int data;
Color color;
Node *left, *right, *parent;
};

class RedBlackTree
{
private:
Node *root;
//protected:
public:


  RedBlackTree() { //constructor
   root = NULL;
  }

bool isRed(Node *elem){ //I had to make this function, it is used in insertfix
  if (elem != NULL && elem->color == RED){
    return true;
  }
  else {
    return false;
  }
}

void rotateLeft(Node*& x) { //implemented from pseudocode
  Node* y = x->right;
  x->right = y->left;
  if (y->left != NULL) {
    y->left->parent = x;
  }
  y->parent = x->parent;
  if (x->parent == NULL ){
    root = y;
  }
  else if (x == x->parent->left) {
    x->parent->left = y;
  }
  else x->parent->right = y;
  y->left = x;
  x->parent = y;
}


void rotateRight(Node*& x) { //same here
  Node* y = x->left;
  x->left = y->right;
  if (y->right != NULL) {
    y->right->parent = x;
  }
  y->parent = x->parent;
  if (x->parent == NULL ){
    root = y;
  }
  else if (x == x->parent->right) {
    x->parent->right = y;
  }
  else x->parent->left = y;
  y->right = x;
  x->parent = y;
}


//public:






void RB_insert_fixup(Node*& z) { //implemented from pseudocode
  Node* y;
  while (isRed(z->parent)) {
    if (z->parent == z->parent->parent->left) {
      y = z->parent->parent->right;
      if (isRed(y)) {
        z->parent->color = BLACK;
        y->color = BLACK;
        z->parent->parent->color = RED;
        z = z->parent->parent;
      }
      else {
      if (z == z->parent->right) {
        z = z->parent;
        rotateLeft(z);
      }
      z->parent->color = BLACK;
      z->parent->parent->color = RED;
      rotateRight(z->parent->parent);
    }
  }
    else {
      y = z->parent->parent->left;
      if (isRed(y)) {
        z->parent->color = BLACK;
        y->color = BLACK;
        z->parent->parent->color = RED;
        z = z->parent->parent;
      }
      else {
      if (z == z->parent->left) {
        z = z->parent;
        rotateRight(z);
      }
      z->parent->color = BLACK;
      z->parent->parent->color = RED;
      rotateLeft(z->parent->parent);
    }
    }

  }
  root->color = BLACK;
}


 Node *binarytreeinsert(Node*& root, Node*& elem) { //simple insert function as the one from last week assignment
                                                    //it will help implementing insert in a redblack tree
        if (root == NULL) {
            return elem;
        }
        if (elem->data < root->data) {
            root->left = binarytreeinsert(root->left, elem);
            root->left->parent = root;
        }
        else if (elem->data > root->data) {
            root->right = binarytreeinsert(root->right, elem);
            root->right->parent = root;
        }
        return root;
    }




void delete_fixup (Node*& x) { //implemented from pseudocode but it show an error I don't know why
  Node* w;
  while (x != root && x->color == BLACK) {
    if (x == x->left) {
      w = x->parent->right;
      if (w->color == RED) {
        w->color = BLACK;
        x->parent->color = RED;
        rotateLeft(x->parent);
        w = x->parent->right;
      }
      if (w->left->color == BLACK && w->right->color == BLACK) {
        w->color = RED;
        x = x->parent;
      }
      else{
         if (w->right->color == BLACK) {
        w->left->color = BLACK;
        w->color = RED;
        rotateRight(w);
        w = x->parent->right;
      }
      w->color = x->parent->color;
      x->parent->color = BLACK;
      w->right->color = BLACK;
      rotateLeft(x->parent);
      x = root;
    }
  }
    else {
      w = x->parent->left;
      if (w->color == RED) {
        w->color = BLACK;
        x->parent->color = RED;
        rotateRight(x->parent);
        w = x->parent->left;
      }
      if (w->right->color == BLACK && w->left->color == BLACK) {
        w->color = RED;
        x = x->parent;
      }
      else{
         if (w->left->color == BLACK) {
        w->right->color = BLACK;
        w->color = RED;
        rotateLeft(w);
        w = x->parent->left;
      }
      w->color = x->parent->color;
      x->parent->color = BLACK;
      w->left->color = BLACK;
      rotateRight(x->parent);
      x = root;
    }
  }
  }

  x->color = BLACK;
}

void transplant(Node* u, Node* v) { //from pseudocode
  if (u->parent == NULL) {
    root = v;
  }
  else if (u == u->parent->left) {
    u->parent->left = v;
  }
  else u->parent->right = v;
  if (v != NULL) {
    v->parent = u->parent;
  }
}


Node* predecessor(Node*& elem) { //symetric to succesor
  Node* y = elem->parent;
  if (elem->left != NULL) {
    return maxsearch(elem->left);
  }
  while (y != NULL && elem == y->left) {
    elem = y;
    y = y->parent;
  }
  return y;
}

Node* successor(const Node*& elem) { //from pseudocode
  Node* y = elem->parent;
  if (elem->right != NULL) {
    return minsearch(elem->right);
  }
  while (y != NULL && elem == y->right) {
    elem = y;
    y = y->parent;
  }
  return y;
}






Node* maxsearch (Node  *elem) { //tree traversal to find max
  while (elem->right != NULL ) {
    elem = elem->right;
  }
  return elem;
}

Node* minsearch (Node* elem) { //same to find min
  while (elem->left != NULL) {
    elem = elem->left;
  }
  return elem;
}

Node* getMinimum() { //apply to R/B tree
  return minsearch(root);
}


Node* getMaximum() {
  return maxsearch(root);
}



Node* helpsearch(Node* elem, int x) { //from last week
  while (elem != NULL && x != elem->data) {
    if (x < elem->data) {
      elem = elem->left;
    }
    else {
      elem = elem->right;
    }
  }
  return elem;
}

Node* search(int x) {
  if (helpsearch(root, x) == NULL){
    cout << "elem not found" << endl;
    return NULL;
}
  else {
    cout << "elem found! " << endl;
    return helpsearch((root), x);
}
}



void insertRB(int x) { //used a helper function in case the root is not null
        Node *elem = new Node;
        elem->data = x;

        if (root == NULL) {
            root = elem;
        }
        else {
            binarytreeinsert(root, elem);
        }
        elem->color = RED;
        elem->left = elem->right = elem->parent = NULL;
        RB_insert_fixup(elem);
    }

void deleteRB(Node*& z) { //implemented from pseudocode
  Node* y = z;
  Color y_ori_color = y->color;
  Node* x;

  if (z->left == NULL) {
     x = z->right;
    transplant(z, z->right);
  }
  else if (z->right = NULL) {
    x = z->left;
    transplant(z, z->left);
  }
  else {
    y = minsearch(z->right);
    y_ori_color = y->color;
    x = y->right;
    if (y->parent == z) {
      x->parent = y;
    }
    else {
      transplant(y, y->right);
      y->right = z->right;
      y->right->parent = y;
    }
    transplant(z, y);
    y->left = z->left;
    y->left->parent = y;
    y->color = z->color;
  }
  if (y_ori_color == BLACK) {
  delete_fixup(x);
}
}


};

int main(){

    RedBlackTree tree;
    tree.insertRB(4);
    tree.insertRB(447);
    tree.insertRB(41);
    tree.insertRB(96);
    tree.insertRB(45);
    tree.insertRB(65);
    cout<<endl;
    cout<<"Tree after succesfull Insertion (Preorder Traversal)"<<endl;


  cout<<"Now Deleting the node 16"<<endl;
   Node *node = tree.search(45);
   tree.deleteRB(node);
    cout << " done";

}
