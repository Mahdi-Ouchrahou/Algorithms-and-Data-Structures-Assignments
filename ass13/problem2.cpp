/*
Mahdi Ouchrahou
m.ouchrahou@jacobsuniversity.de
hw 13 problem 13.2
*/

/*
algorithm formulation:
I will use Dijkatras algorithm two times on the same graph onec given the node p and once given the node q, we store the given shortest paths
in two arrays.
Then we use a finction that minimize the distance between the two found shortest paths, store searched node (city)

*/


#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include <climits>

using namespace std;

//value of infinity
# define infinity INT_MAX;

typedef pair<int, int> node;

int find_meetup_city(int **adj_matx, int my_city, int friend_city, int n) {
  int fromp_dist[n]; //shortest path from p

  for(int i=0; i<n; i++) { //initialize all nodes to infinty
    fromp_dist[i] = infinity;
  }
  fromp_dist[my_city] = 0; //distance from root is 0
  priority_queue<node, vector<node>, greater<node> > Queue1; //create a min priority queue reference at https://www.geeksforgeeks.org/priority-queue-of-pairs-in-c-with-ordering-by-first-and-second-element/?ref=rp
  Queue1.push(make_pair(0, my_city)); //push root in queue with key 0, I created a pair object using make_pair(), reference at https://www.cplusplus.com/reference/utility/make_pair/

  while (!Queue1.empty()) {
    int u = Queue1.top().second;
    Queue1.pop(); //pop node from queue
    for(int i=0; i<n; i++){ //for all nodes in adj matrix
      int distance = adj_matx[u][i]; //hold wight(u, my_city)
      if ((fromp_dist[i] > fromp_dist[u] + distance) && distance !=0){
        fromp_dist[i] = fromp_dist[u] + distance; //update distance / relax
        Queue1.push(make_pair(fromp_dist[i-1], i));
      }
    }
  }


//repeate same as bellow for my friend's city node
  int fromq_dist[n];

  for(int i=0; i<n; i++) {
    fromq_dist[i] = infinity;
  }
  fromq_dist[friend_city] = 0;
  priority_queue<node, vector<node>, greater<node> > Queue2;
  Queue2.push(make_pair(0, friend_city));

  while (!Queue2.empty()) {
    int u = Queue2.top().second;
    Queue2.pop();
    for(int i=0; i<n; i++){
      int distance = adj_matx[u][i];
      if ((fromq_dist[i] > fromq_dist[u] + distance) && distance !=0){
        fromq_dist[i] = fromq_dist[u] + distance;
        Queue2.push(make_pair(fromq_dist[i-1], i));
      }
    }
  }
  //finction that minimizes the distance from p to q, in this case fromp_dist to fromq_dist
  //we set a variable compare, initially infinity
  int compare = infinity;
  //variable that will hold index(vertex) of the searched city
  int city = 0;

  for (int i=0; i<n; i++) {
    if (i != my_city && i != friend_city) {
      if (compare > max(fromp_dist[i], fromq_dist[i])) { //use max() function from alg library
        compare = max(fromp_dist[i], fromq_dist[i]);
        city = i;
      }

    }
  }

  return city;
}


int main() {
  int u, v; //holding two city start point
  int size =0;

  cout << "Enter size:" << endl;
  cin >> size;



  int **adjmatrix;
  adjmatrix = new int*[size];
   // allocate memory for the adj matrix
	for(int i = 0; i<size; i++){
		adjmatrix[i] = new int[size];
	}

  cout<<"Fill the 4x4 Adjacency Matrix"<<endl;
    for (int i = 0; i < size; i++){
        for (int j = 0; j < size; j++){
          cout << "Adjacency matrix [" << i << "][" << j << "] : ";
            cin>>adjmatrix[i][j];
        }
    }

    cout << "Enter your actual city" << endl;
    cin >> u;
    cout << "enter your friend's city" << endl;
    cin >> v;

    cout << "optimum place to meet is city" << find_meetup_city(adjmatrix, u, v, size) << endl;


//free memory
for (int i=0; i<size; i++) {
  delete []adjmatrix[i];
}
delete []adjmatrix;






}
