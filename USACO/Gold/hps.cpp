#include "bits/stdc++.h"

using namespace std;

int dp[3][100001][21];

bool win(int a, int b){
    return (a == 1 && b == 0) || (a == 2 && b == 1) || (a == 0 && b == 2);
}

int main(){
    freopen("hps.in", "r", stdin);
    freopen("hps.out", "w", stdout);
    cin.tie(0)->sync_with_stdio(0);
    
    int n, k;
    cin >> n >> k;
    vector<int> farmer(n+1);
    for(int i = 1; i <= n ;i ++){
        char c;
        cin >> c;
        if(c == 'H') farmer[i] = 0;
        if(c == 'P') farmer[i] = 1;
        if(c == 'S') farmer[i] = 2;
    }
    
    for(int i = 0; i <= k; i++){
        for(int j = 0; j < n; j++){
            for(int k = 0; k < 3; k++){
                dp[k][j+1][i] = max(dp[k][j+1][i], dp[k][j][i] + (win(k, farmer[j+1]) ? 1 : 0));
                dp[(k+1)%3][j+1][i+1] = max(dp[(k+1)%3][j+1][i+1], dp[k][j][i] + (win((k+1)%3, farmer[j+1]) ? 1 : 0));
                dp[(k+2)%3][j+1][i+1] = max(dp[(k+2)%3][j+1][i+1], dp[k][j][i] + (win((k+2)%3, farmer[j+1]) ? 1 : 0));
            }
        }
    }

    cout << max(max(dp[0][n][k], dp[1][n][k]), dp[2][n][k]) << endl;



}