#include "bits/stdc++.h"
using namespace std;
using ll = long long;
ll arr[200000];

int main(){
    cin.tie(0) -> sync_with_stdio(0);

    int t;
    cin >> t;
    while(t--){
        int n ;
        cin >> n;
        for(int i = 0; i < n ;i++){
            cin >> arr[i];
        }
        ll ans = 0;
        ll dif = 0;

        for(int i = n-2; i >= 0; i--){
            arr[i] -= dif;
            if(arr[i] > arr[i+1]){
                ans += abs(arr[i+1] - arr[i]);
                dif += abs(arr[i+1] - arr[i]);
                arr[i] = arr[i+1];
            }
        }
        
        if(arr[0] < 0) ans += abs(arr[0]) + arr[n-1] + abs(arr[0]);
        else ans += arr[n-1];
        cout << ans << endl;
    }
}