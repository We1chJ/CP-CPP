#include "bits/stdc++.h"
using namespace std;

using ll = long long;
int main(){
    cin.tie(0)->sync_with_stdio(0);
    int t = 0;
    cin >> t;
    while(t--){
        ll n, l, r, k;
        cin >> n >> l >> r >> k;
        if(n == 2){
            cout << -1 << endl;
            continue;
        } 
        if(n%2 == 1){
            cout << l << endl;
        }else{
            ll res = 1;
            while(!(res >= l && (res & l) == 0)){
                res <<= 1;
            }
            if(res > r || n == 2)
                cout << -1 << endl;
            else{
                if(k < n-1)
                    cout << l << endl;
                else
                    cout << res << endl;
            }
        }
    }
}