// sparse table good for min query

#include "bits/stdc++.h"

using namespace std;

const int MAXN = 2e5;
const int k = 18;
int st[MAXN][k+1];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, q;
    cin >> n >> q;
    for(int i = 0; i < n; i++){
        cin >> st[i][0];
    }

    // range minimum query
    for(int j = 1; j <= k ; j++){
        for(int i = 0; i + (1 << j) <= n; i++){
            st[i][j] = min(st[i][j-1], st[i + (1 << (j-1))][j-1]);
        }
    }

    // queries
    // precompute log
    int log[MAXN+1];
    log[1] = 0;
    for(int i = 2; i <= MAXN; i++){
        log[i] = log[i/2] + 1;
    }

    for(int i = 0; i  < q; i++){
        int l, r;
        cin >> l >> r;
        l -=1;
        r -=1;
        cout << min(st[l][log[r-l+1]], st[r - (1 << log[r-l+1]) + 1][log[r-l+1]]) << endl;
    }
    return 0;
}