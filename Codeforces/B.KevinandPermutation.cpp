#include "bits/stdc++.h"
using namespace std;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int t;
    cin >> t;
    while(t--){
        int n ;
        cin >> n ;
        int a = n/2;
        vector<pair<int, int>> v;
        for(int i = 1; i <= n/2; i++){
            v.push_back({i, i + a});
        }
        reverse(v.begin(), v.end());
        for(auto a : v){
            cout << a.first << " " << a.second << " ";
        }
        if(n%2 == 1)
            cout << n;
        cout << endl;
    }
}