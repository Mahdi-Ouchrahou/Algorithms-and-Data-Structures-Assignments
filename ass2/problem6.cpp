/*
Mahdi Ouchrahou
m.ouchrahou@jacobs-university.de
Assignment 2 problem 6
*/
#include <iostream>
#include <fstream>
#include <map>
using namespace std;

int main()
{
    ifstream f;
    map<string, string> my_map; //declaring container
    f.open("data.txt"); //open data.txt
    string name;
    string birthday;
    while (getline(f, name)) //loop to get data from our file
    {

        getline(f, birthday);
        my_map[name] = birthday;
    }
    f.close(); //closing data.txt
    while (1) //infinite loop
    {
        cout << "Enter your name: ";
        getline(cin, name);
        if(my_map[name]=="") cout << "name not found"<<endl; //check if name is in the file
        else cout << my_map[name] << endl; //print corresponding date
    }
    return 0;
}
