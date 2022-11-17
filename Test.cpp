#include "bits/stdc++.h"
using namespace std;

using ll = long long;
const int MAX = 2e5;
const int k = 18;

int st[MAX][k+1];



int main(){
    cin.tie(0)->sync_with_stdio(0);
    int n, q;
    cin >> n >> q;
    
    for(int i = 0; i < n; i++){
        cin >> st[i][0];
    }

    for(int pow = 1; pow <= k; pow++){
        for(int i = 0; i + (1 << pow) <= n; i++){
            st[i][pow] = min(st[i][pow-1], st[i + (1 << (pow-1))][pow-1]);
        }
    }
    int log[MAX + 1];
    log[1] = 0;
    for(int i = 2; i <= MAX; i++){
        log[i] = log[i/2] + 1;
    }

    for(int i = 0; i < q; i++){
        int a, b;
        cin >> a >> b;
        a -= 1;
        b -= 1;
        cout << min(st[a][log[b-a+1]], st[b - (1 << log[b-a+1]) + 1][log[b-a+1]]) << endl;
    }
}