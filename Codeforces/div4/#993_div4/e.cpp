#include "bits/stdc++.h"
using ll = long long;
using namespace std;

int main(){
    cin.tie(0)->sync_with_stdio(0);

    int t;
    cin >> t;
    while(t--){
        ll k, l1, r1, l2, r2;
        cin >> k >> l1 >> r1 >> l2 >> r2;
        ll kn = 1;
        ll ans = 0;
        while(kn <= 1e9){
            ll upper = min(r1, r2/kn);
            ll lower = max(l1, (l2 + kn-1)/kn);
            ans += max(0LL, (upper - lower + 1));
            kn *= k;
        }
        cout << ans << endl;
    }
}