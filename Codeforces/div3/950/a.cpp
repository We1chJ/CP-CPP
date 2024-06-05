#include "bits/stdc++.h"
using namespace std;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int t;
    cin >>t;
    while(t--){
        int n, m;
        cin >> n  >> m;
        string s ;
        cin >> s;
        vector<int> v (7, m);
        for(int i = 0; i < n; i++){
            v[(s[i] - 'A')]--;
        }
        int ans = 0;
        for(int &a : v){
            if(a > 0)
                ans += a;
        }
        cout << ans << endl;
    }
}