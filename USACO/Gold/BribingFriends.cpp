#include "bits/stdc++.h"

using namespace std;

const int N = 2001;

int dp[N][2*N];

void set_max(int &a, int b){
    if(b > a) a = b;
}

int main(){
    cin.tie(0)->sync_with_stdio(0);

    int n, moonie, cones;
    cin >> n >> moonie >> cones;

    vector<array<int, 3>> cows(n);
    for(auto &[x, p, c] : cows){
        cin >> p >> c >> x;
    }

    sort(cows.begin(), cows.end());

    memset(dp, -1, sizeof dp);

    dp[0][moonie + cones] = 0;
    for(int i = 0; i < n; i++){
        auto [x, p, c] = cows[i];
        for(int j = 0; j <= moonie + cones; ++j){
            if(dp[i][j] == -1) continue;

            // so j how many moonies + cones, first half moonie, and when exceeds moonies, then it represents number of cones available

            set_max(dp[i+1][j], dp[i][j]);
            if(j - c*x >= moonie){ // bribe with all
                set_max(dp[i+1][j-c*x], dp[i][j] + p); // use all cones to bribe
            }else if(j > moonie){ // bribe partially with some cones and having all moonies available
                int cost_left = c - (j - moonie)/x; // j-moonie = cones to use
                if(moonie - cost_left >= 0)
                    set_max(dp[i+1][moonie - cost_left], dp[i][j] + p);
            }else if(j <= moonie && j - c >= 0){ // no cones available
                set_max(dp[i+1][j-c], dp[i][j] + p); // not bribe at all
            }
        }
    }
    cout << *max_element(dp[n], dp[n] + moonie + cones + 1) << endl;
}