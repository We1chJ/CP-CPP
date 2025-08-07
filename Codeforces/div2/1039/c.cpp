#include "bits/stdc++.h"

using namespace std;

using ll = long long;
int main(){
    cin.tie(0) -> sync_with_stdio(0);
    
    int t;
    cin >> t;
    while(t--){
        int n ;
        cin >> n;
        vector<int> v(n);
        for(int i= 0; i < n; i++){
            cin >> v[i];
        }

        int mn = v[0];
        bool work = true;
        for(int i  =1; i < n ;i++){
            int cur = v[i];
            if(cur != 1 && cur/2+1 > mn){
                work = false;
                break;
            }else{
                mn = min(v[i], mn);    
            }
        }
        cout << (work ? "YES" : "NO") << endl;
    }
}