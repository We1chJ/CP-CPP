#include "bits/stdc++.h"
using ll = long long;
using namespace std;

int main(){
    cin.tie(0)->sync_with_stdio(0);

    int t;
    cin >> t;
    while(t--){
        int n = 0;
        cin >> n;
        
        vector<int> v(n);
        set<int> avai;
        for(int i  = 1; i <= n; i++){
            avai.insert(i);
        }
        for(int i = 0; i < n; i++){
            cin >> v[i];
            avai.erase(v[i]);
        }
        // for(auto x : avai) {
        //     cout << x << " ";
        // }
        // cout << endl;
        vector<int> ans(n);
        set<int> s;
        for(int i=0 ; i < n ;i ++){
            if(s.count(v[i])){
                ans[i] = *avai.begin();
                avai.erase(*avai.begin());
            }else{
                ans[i] = v[i];
                s.insert(v[i]);
            }
        }

        for(auto a : ans){
            cout << a << " ";
        }
        cout << endl;
        
        

    }
}