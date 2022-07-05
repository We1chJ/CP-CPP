#include "bits/stdc++.h"


using namespace std;

bool dp[5000001];

int n, a, b;
void update(int pos, int count){
    if(dp[pos] || pos > n) return;
    dp[pos] = true;
    update(pos + a, count);
    update(pos + b, count);
    if(count == 0)
        update(pos/2, 1);
}

int main(){
    // cin.tie(0) -> sync_with_stdio(0);

    freopen("feast.in", "r", stdin);
    freopen("feast.out", "w", stdout);
    cin >> n >> a >> b;
    
    update(0, 0);

    for(int i = n ;i >= 0; i--){
        if(dp[i]){
            cout << i << endl;
            return 0;
        }
    }
    return 0;
}
