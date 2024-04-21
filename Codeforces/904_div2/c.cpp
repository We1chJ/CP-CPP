#include "bits/stdc++.h"

using namespace std;

using ll = long long;

const int MOD = 1e9+7;

int main(){
    cin.tie(0)->sync_with_stdio(0);

    vector<int> fac (3e5+5);
    fac[0] = 1;
    for(ll i = 1; i < fac.size(); i++){
        fac[i] = fac[i-1]*i % MOD;
    }

    int t ;
    cin >> t;
    while(t--){
        int n, k;
        cin >> n >> k;
        int placed = 0;
        for(int i = 0; i < k; i++){
            int a , b;
            cin >> a >> b;
            if(a == b) placed++;
            else placed += 2;
        }

        int rooks = n - placed;
        ll ans = 0;
        for(int i = 0; i <= rooks/2; i++){
            ans = (ans + fac[rooks/2]/fac[i]*2%MOD)%MOD;
        }

        // TODO: probably involves multiplicative inverse cuz i need to divide for permutations

        cout << ans << endl;

    }    
}