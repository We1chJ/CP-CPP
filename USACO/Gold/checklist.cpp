#include "bits/stdc++.h"

using ll = long long;

using namespace std;

vector<pair<int, int>> hol(1001);
vector<pair<int, int>> ger(1001);

ll dis(int a, int i, int b, int j){
    auto px = i == 0 ? hol[a] : ger[a];
    auto py = j == 0 ? hol[b] : ger[b];
    int x = px.first - py.first;
    int y = px.second - py.second;
    return x*x + y * y;
}
int main(){

    freopen("checklist.in", "r", stdin);
    freopen("checklist.out", "w" , stdout);
    cin.tie(0)->sync_with_stdio(0);
    int h, g;
    cin >> h >> g;

    for(int i =1 ; i <= h; i++){
        int a, b;
        cin >> a>> b;
        hol[i] = {a, b};
    }

    for(int i =1 ; i <= g; i++){
        int a, b;
        cin >> a>> b;
        ger[i] = {a, b};
    }
    ll dp[h+1][g+1][2];

    
    for(int i = 0; i <= h; i++){
        for(int j = 0; j <= g; j++){
            for(int k = 0; k < 2; k++){
                dp[i][j][k] = (ll)1 << 60;
            }
        }
    }
    dp[1][0][0] = 0;
    for(int i = 0; i <= h; i++){
        for(int j = 0; j <= g; j++){
            for(int k = 0; k < 2; k++){
                if(k == 0 && i == 0) continue;
                if(k == 1 && j == 0) continue;
                pair<int,int> source;
					if(k == 0) source = {i, 0};
					else source = {j, 1};
                if(i < h)
                    dp[i+1][j][0] = min(dp[i+1][j][0], dp[i][j][k] + dis(i+1, 0, source.first, source.second));
                if(j < g)
                    dp[i][j+1][1] = min(dp[i][j+1][1], dp[i][j][k] + dis(j+1, 1, source.first, source.second));
            }
        }
    }
    cout << dp[h][g][0] << endl; 
}