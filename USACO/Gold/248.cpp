#include <bits/stdc++.h>

using namespace std;
int n;
int dp[249][249];
int main(){
    freopen("248.in", "r", stdin);
	freopen("248.out", "w", stdout);
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> dp[i][1];
    }
    for(int l = 2; l <= n; l++){
        for(int i = 0; i + l-1 < n; i++){
            for(int k = 1; k < l; k++){
                int a = dp[i][k];
                int b = dp[i+k][l-k];
                if(a != 0 && a == b) dp[i][l] = a+1;
            }
        }
    }

    int ans = 0;
    for(int i = 0; i <= n ; i++){
        for(int j = 0; j <= n; j++){
            ans = max(dp[i][j], ans);
        }
    }
    if(n == 2 && dp[0][1] == dp[1][1]) cout << dp[0][1]+1 << endl;
    else if(n == 2) cout << max(dp[0][1], dp[1][1]);
    else cout << ans << endl;

}