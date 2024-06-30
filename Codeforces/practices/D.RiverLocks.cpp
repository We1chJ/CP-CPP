#include "bits/stdc++.h"
using namespace std;
using ll = long long;

int main(){
    cin.tie(0) -> sync_with_stdio(0);

    int n;
    cin >> n;
    ll prefix[n+1];
    vector<ll> dp(n+1, 0);
    prefix[0] = 0;
    for(int i= 0; i < n; i++){
        int num;
        cin >> num;
        prefix[i+1] = num + prefix[i];
    }
    ll total = prefix[n];
    dp[1] = total;
    ll maxT = prefix[1];
    for(int i = 2; i <= n; i++){
        dp[i] = max(maxT, (total%i == 0) ? total/i : (total/i + 1));
        maxT = max(maxT, (prefix[i]%i == 0) ? prefix[i]/i : (prefix[i]/i + 1));
    }

    int q;
    cin >> q;
    for(int i = 0; i < q; i++){
        int l = 1;
        int r = n;
        int t;
        cin >> t;

        while(l < r){
            int mid = (l+r)/2;
            if(dp[mid] <= t)
                r = mid;
            else 
                l = mid + 1;
        }
        if(dp[r] <= t)
            cout << l << endl;
        else
            cout << -1 << endl;
    }

}