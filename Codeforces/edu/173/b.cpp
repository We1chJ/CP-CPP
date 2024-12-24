#include "bits/stdc++.h"

using namespace std;
using ll = long long;

// lower bound at n=7
vector<ll> fact = {
    0ll,
    1ll,
    1ll * 2ll,
    1ll * 2ll * 3ll,
    1ll * 2ll * 3ll * 4ll,
    1ll * 2ll * 3ll * 4ll * 5ll,
    1ll * 2ll * 3ll * 4ll * 5ll * 6ll,
    1ll * 2ll * 3ll * 4ll * 5ll * 6ll * 7ll,
};
int main(){
    cin.tie(0) -> sync_with_stdio(0);
    int t;
    cin >> t;
    while(t--){
        ll n, d;
        cin >> n >> d;

        ll amt = fact[min(n, (ll)fact.size()-1)];

        for(int f=1; f<=9; f+=2){
            int v = d;
            for(int i =1; i < amt; i++){
                v = (v*10+d)%f;
            }
            if(v%f == 0)
                cout << f << " ";
        }
        cout << endl;
    }
}