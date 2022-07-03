#include "bits/stdc++.h"

using namespace std;
using ll = long long;
const ll MOD = 1e9+7;
ll dp[1 << 20][20];

vector<int> adj[20];

int main(){
    cin.tie(0) -> sync_with_stdio(0);

    int n, m;
    cin >> n >> m;
    for(int i = 0; i < m ;i++){
        int a , b;
        cin >> a >> b;
        adj[b-1].push_back(a-1);
    }

    dp[1][0] = 1;
    for(int i = 2; i < (1 << n); i++){
        if((i & 1) == 0) continue;

        if((i & (1 << n-1)) && i != ((1<< n) - 1)) continue;
        for(int a = 0; a < n; a++){
            if((i & (1 << a)) == 0) continue;

            int prev = i - (1 << a);
            for(auto j : adj[a]){
                if((i & (1 << j))){
                    dp[i][a] += dp[prev][j];
                    dp[i][a] %= MOD;
                }
            }
        }
    }

    cout << dp[(1 << n)-1][n-1] << endl;

}