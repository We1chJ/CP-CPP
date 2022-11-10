#include "bits/stdc++.h"

using ll = long long;
using namespace std;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int t;
    cin >> t;
    for(int _ = 1; _ <= t; _++){
        int d, n, x;
        cin >> d >> n >> x;
        int num[n+1], days[n+1], val[n+1];
        for(int i = 1; i <= n; i++){
            cin >> num[i] >> days[i] >> val[i];
        }
        int dp[d+1][n+1];
        for(int i = 1; i <= n; i++){
            dp[0][i] = 0;
            for(int j = 1; j <= d; j++){
                if(days[i] <= d - j){
                    dp[i][j] = max(dp[i][j], dp[i-1][j-1] + val[i]);
                }
            }
        }
        cout << "Case #" << _ << ": " << dp[d][n] << endl;
    }

}