#include "bits/stdc++.h"

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    int arr[n+1];
    for(int i = 0; i < n; i++){
        cin >> arr[i+1];
    }

    int dp[n+1];
    
    for(int i = 0; i <= n; i++) dp[i] = INT_MAX;

    dp[1] = 0;
    for(int i = 1; i <= n ; i++) {
        if(i + 1 <= n) dp[i+1] = min(dp[i+1], abs(arr[i+1] - arr[i]) + dp[i]); 
        if(i + 2 <= n) dp[i+2] = min(dp[i+2], abs(arr[i+2] - arr[i]) + dp[i]); 
    }

    cout << dp[n];
    return 0;
}