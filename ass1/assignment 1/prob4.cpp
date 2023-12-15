/* Mahdi Ouchrahou
   m.ouchrahou@jacobs-university.de
   ass 1 prob 4 
*/
#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main (){
  vector<string> vectorstring(0);
  int idx = 0;
  string s;
  cin >> s;
  //loop will repeat untill "END" is entered
  while (1){
    if (s != "END") {
      getline(cin, s);
      vectorstring.push_back(s); // pushback method of the strings in our vector 
      idx++;
    }
    else break;
  }
//the first print 
  for(int i=-1; i<idx; i++){
    cout << vectorstring[i+1] << " ";
  }
  cout << endl;
//the second prrint
  for (int j=-2; j<idx; j++){
    cout << vectorstring[j+2] << " ";
    }
    cout << endl;

    return 0;

}
