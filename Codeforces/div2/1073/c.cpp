#include "bits/stdc++.h"

using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >>n ;
        string s;
        cin >> s;

        string cp = s;
        sort(cp.begin(), cp.end());
        if(cp == s){
            cout << "Bob" << endl;
            continue;
        }
        
        cout << "Alice" << endl;
        vector<int> ind;
        for(int i = 0; i <n; i++){
            if(s[i] != cp[i]) ind.push_back(i+1);
        }
        cout << ind.size() << endl;
        for(auto & a : ind) {
            cout << a << " ";
        }

        cout << endl;

    }
}