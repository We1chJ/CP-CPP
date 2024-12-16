#include "bits/stdc++.h"
using ll = long long;
using namespace std;

int main(){
    cin.tie(0)->sync_with_stdio(0);

    int t;
    cin >> t;
    while(t--){
        int m, a, b,c;
        cin >> m >> a >> b >> c;
        int r1 = 0, r2 = 0;
        r1 += min(a, m);
        r2 += min(b, m);

        cout << r1 + r2 + min(m-r1+m-r2, c) << endl;
    }
}