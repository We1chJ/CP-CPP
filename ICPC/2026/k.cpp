#include "bits/stdc++.h"
using namespace std;

int main(){

    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        set<int> s;
        string str = "123456789";
        for(int i = 0; i < str.size(); i++){
            for(int j = 1; i+j-1 < str.size(); j++){
                s.insert(stoi(str.substr(i, j)));
            }
        }

        auto it = s.lower_bound(n);
        if(it == s.end()) cout << -1 << endl;
        else cout << *it << endl;
    }

}
