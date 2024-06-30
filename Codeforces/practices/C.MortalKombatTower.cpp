#include "bits/stdc++.h"

using namespace std;

const int INF = 1e9 + 5;
int a[200000];
int main(){
    cin.tie(0) -> sync_with_stdio(0);
    int t;
    cin >> t;
    while(t--){
        int n ;
        cin >> n;
        for(int i = 0; i < n; i++){
            cin >> a[i];
        }
        vector<array<int, 2>> dp(n+1, {INF, INF});
        dp[0][1] = 0;
        for (int i = 0; i < n; i++)
            for (int who = 0; who < 2; who++)
                for (int fight = 1; fight <= min(n - i, 2); fight++) {
                    int hard = a[i] + (fight > 1 ? a[i + 1] : 0);
                    dp[i + fight][!who] = min(dp[i + fight][!who], dp[i][who] + who * hard);
                }
        cout << min(dp[n][0] , dp[n][1]) << endl;
    }
}