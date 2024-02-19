#include "bits/stdc++.h"

using namespace std;

int main(){

    cin.tie(0) -> sync_with_stdio(0);

    int t;
    cin >> t;
    for(int a = 0; a < t; a++){
        int n;
        cin >> n;
        string arr[n];
        unordered_set<string> s;
        for(int i = 0; i < n ; i++){
            string x;
            cin >> x;
            s.insert(x);
            arr[i] = x;
        }
        for(int i = 0; i < n ; i++){
            bool done = false;
            for(int j = 0 ; j < arr[i].length(); j++){
                string s1 = arr[i].substr(0, j);
                string s2 = arr[i].substr(j, arr[i].length());
                if(s.count(arr[i].substr(0, j)) != 0 && s.count(arr[i].substr(j, arr[i].length())) != 0){ 
                    done = true;
                    break;
                }
            }
            if(done) cout << 1;
            else cout << 0;
        }
        cout << endl;
    }
}