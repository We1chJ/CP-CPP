#include "bits/stdc++.h"

using namespace std;
using ll = long long;

int main(){
    cin.tie(0) -> sync_with_stdio(0);
    int t;
    cin >> t;
    while(t--){
        ll n;
        cin >> n;
        ll ans = 1;
        while(n > 3){
            ans *= 2;
            n /= 4;
        }
        cout << ans << endl;
    }
}