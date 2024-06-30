#include "bits/stdc++.h"
using namespace std;


int main(){
    cin.tie(0)->sync_with_stdio(0);
    int n ;
    cin >> n;
    string str;
    cin >> str;

    int totalL = 0, totalO = 0;
    for(int i = 0; i < str.length(); i++){
        if(str[i] == 'L') totalL ++;
        else totalO ++;
    }

    // cout << totalL << " " << totalO << endl;
 
    int curL = 0, curO = 0;
    for(int i = 0; i < str.length()-1; i++){
        if(str[i] == 'L') 
            curL++;
        else
            curO++;
        
        // cout << curL << " " << curO << endl;
        if((curL !=(totalL-curL)) && (curO != (totalO-curO))){
            cout << i+1 << "\n";
            return 0;
        }
    }

    cout << -1 << "\n";
    return 0;
}