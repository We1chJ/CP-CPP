#include"bits/stdc++.h"
using namespace std;
using ll = long long;

ll dp[201][201][201];

int P[201], C[201], X[201];
int main(){
    cin.tie(0)->sync_with_stdio(0);

    int N, A, B;
    cin >> N >> A >> B;
    for(int i = 1; i <= N; i ++){
        cin >> P[i] >> C[i] >> X[i];
    }

    for(int i = 1; i <= N; i++){
        for(int j = 0; j <= A; j++){
            for(int k = 0; k <= B; k++){
                dp[i][j][k] = max(dp[i-1][j][k], dp[i][j][k]);
                for(int a = 0; a <= k && a <= C[i]*X[i]; a ++){
                    if(j-(C[i] - a/X[i]) < 0) continue;
                    dp[i][j][k] = max(dp[i][j][k], dp[i-1][j-(C[i] - a/X[i])][k-a] + P[i]);
                }
            }
        }
    }

    // for(int i = 0; i<= N; i++){
    //     for(int j = 0; j <= A; j++){
    //         for(int k = 0; k <= B; k++){
    //             cout << dp[i][j][k] << " ";
    //         }
    //         cout << endl;
    //     }
    //     cout << "==================" << endl;
    // }

    cout << dp[N][A][B] << endl;
}
