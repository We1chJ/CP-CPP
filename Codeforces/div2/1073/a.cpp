#include "bits/stdc++.h"

using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >>n ;
        vector<pair<int,int>> v(n);
        for(int i = 0; i < n; i++){
            int a;
            cin >>a;
            v[i] = {a, i};
        }
        sort(v.begin(), v.end());
        bool ans = true;
        for(int i = 0; i < n-1; i++){
            int i1 = v[i].second;
            int i2 = v[i+1].second;
            if(i1%2 == i2%2){
                ans = false;
                break;
            }
        }
        cout << (ans ? "YES" : "NO") << endl;
    }
}