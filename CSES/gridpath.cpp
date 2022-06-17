#include "bits/stdc++.h"

using namespace std;

int dp[1000][1000];
bool hasTrap[1000][1000];

const int MOD = 1e9+7;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    for(int i = 0; i < n; i++){
        string s;
        cin >> s;
        for(int j = 0; j < n; j++){
            if(s[j] == '*') hasTrap[i][j] = true;
        }
    }

    for(int i = 0; i < n ; i++){
        for(int j = 0; j < n; j ++){
            if(i == 0 && j == 0) dp[0][0] = 1;
            else if(i == 0) dp[0][j] = dp[0][j-1];      
            else if(j == 0) dp[i][0] = dp[i-1][0];           
     
            if(i != 0 && j != 0) dp[i][j] = (dp[i-1][j] + dp[i][j-1])%MOD;
            if(hasTrap[i][j]) dp[i][j] = 0;   
        }
    }

    cout << dp[n-1][n-1] << endl;
    
    return 0;
}