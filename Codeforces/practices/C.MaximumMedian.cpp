#include "bits/stdc++.h"
using namespace std;

using ll = long long;

int main(){
    cin.tie(0) -> sync_with_stdio(0);
    int n, k;
    cin >> n >> k;
    vector<ll> arr(n);
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    sort(arr.begin(), arr.end());

    ll l = arr[(n-1)/2];
    ll r = l + k;
    while(l < r){
        ll mid = (l + r + 1)/2;
        ll sum = 0;
        for(int i = (n-1)/2; i < n && arr[i] < mid; i++){
            sum += mid - arr[i];
        }
        if(sum <= k)
            l = mid;
        else 
            r = mid-1;
    }
    cout << l << endl;
}