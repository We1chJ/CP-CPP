#include "bits/stdc++.h"

using namespace std;

using ll = long long;

int dp[501][501];

int main(){
    cin.tie(0) -> sync_with_stdio(0);

    string str;
    cin >> str;
    int n = str.length();

    for(int j = 0; j <= n; j++){
        for(int i = 0; i < n - j; i++){
            dp[i][i + j] = dp[i+1][i+j] + 1;
            for(int k = i + 1; k <= i + j; k ++){
                if(str[i] == str[k]){
                    dp[i][i+j] = min(dp[i][i+j], dp[i+1][k-1] + dp[k + 1][i + j]);
                }
            }
        }
    }

    cout << dp[0][n-1] << endl;
}