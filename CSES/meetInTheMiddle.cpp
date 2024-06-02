#include "bits/stdc++.h"

using namespace std;
using ll = long long;

int main(){
    cin.tie(0) ->sync_with_stdio(0);
    
    int n, x;
    cin >> n >> x;

    vector<int> arr (n);
    for(int i = 0 ; i < n ; i++){
        cin >> arr[i];
    }

    vector<ll> sums1;
    for(int i = 0; i < (1 << (n/2)); i++){
        ll t = 0;
        for(int j = 0; (1 << j) <= i; j++){
            if(i & (1 << j)){
                t += arr[j];
            }
        }
        sums1.push_back(t);
    }
    vector<ll> sums2;
    for(int i  = 0; i < (1 << (n - n/2)); i++){
        ll t = 0;
        for(int j = 0; (1 << j) <= i; j++){
            if(i & (1 << j)){
                t += arr[(n/2) + j];
            }
        }
        sums2.push_back(t);
    }

    sort(sums1.begin(), sums1.end());       
    sort(sums2.begin(), sums2.end());       

    ll ans = 0;

    for(ll i : sums1){
        auto low = lower_bound(sums2.begin(), sums2.end(), x - i);
        auto high = upper_bound(sums2.begin(), sums2.end(), x - i);
        ans += (high - sums2.begin()) - (low - sums2.begin());
    }
    cout << ans << endl;

}