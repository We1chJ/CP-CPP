#include "bits/stdc++.h"

using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        int n, m, h;
        cin >> n >> m >> h;
        vector<int> v (n);
        for(int i = 0 ; i < n; i++){
            cin >> v[i];
        }
        unordered_map<int, int> mp;

        for(int i = 0 ; i < m; i++){
            int b, c ;
            cin >> b >> c;
            b--;
            mp[b] += c;
            if(mp[b]+v[b] > h){
                mp.clear();
            }
        }

        for(int i = 0; i< n;i ++){
            if(mp.count(i)){
                v[i] += mp[i];
            }
            cout << v[i] << " ";
        }
        cout << endl;

    }


}