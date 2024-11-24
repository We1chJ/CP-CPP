#include "bits/stdc++.h"

using namespace std;

int main(){
    cin.tie(0)->sync_with_stdio(0);


    int group = -1;

    // get to meet in the cycle
    do{
        string line;
        cout << "next 0 1" << endl;
        cout.flush();
        getline(cin,line);
        
        cout << "next 1" << endl;
        cout.flush();        
        
        // Read the first line
        getline(cin, line);
        group = line[0] - '0';
    }while(group != 2);

    // everyone run towards the finish vertex
    do{
        string line;
        cout << "next 0 1 2 3 4 5 6 7 8 9" << endl;
        cout.flush();     
        
        getline(cin, line);
        group = line[0] - '0';
    }while(group != 1);
    cout << "done" << endl;
    cout.flush();

}