#include "bits/stdc++.h"

using namespace std;
using ll = long long;
const int MOD = 1000000007;

int n, k;


ll dp[500000][3];

int color[500000];

vector<int> adj[500000];

ll dfs(int cur, int curColor, int par, int parColor){
    if((parColor == curColor) ||  (color[cur] >= 0 && curColor != color[cur])) return 0;
    if(dp[cur][curColor] >= 0) 
			return dp[cur][curColor];
    dp[cur][curColor] = 1;
    for(auto a : adj[cur]){
        if(a == par) continue;
        ll canColor = 0;
        for(int i = 0; i < 3; i++){
            canColor += dfs(a, i, cur, curColor);
            canColor %= MOD;  
        }
        dp[cur][curColor] *= canColor;
        dp[cur][curColor] %= MOD;
    }
    return dp[cur][curColor];
}


int main(){
    freopen("barnpainting.in", "r", stdin);
    freopen("barnpainting.out", "w", stdout);

    cin.tie(0)->sync_with_stdio(0);

    cin >> n >> k;

    for(int i= 0; i < n; i ++){
        color[i] = -1;
        dp[i][0] = dp[i][1] = dp[i][2] = -1;
    }

    for(int i = 0; i < n-1; i++){
        int a, b;
        cin >> a >> b;
        a--, b--;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    for(int i = 0; i < k; i++){
        int a, c;
        cin >> a >> c;
        a--;
        color[a] = c-1;
    }
    ll ans = dfs(0, 0, -1, -1) + dfs(0, 1, -1, -1) + dfs(0, 2, -1, -1);
    cout << ans%MOD << endl;
}