#include "bits/stdc++.h"

using namespace std;

int main(){
    cin.tie(0)->sync_with_stdio(0);

    int n;
    cin >> n;
    vector<int> v(n);
    for(int i = 0;i < n; i++){
        cin >> v[i];
    }
    long long ans = -accumulate(v.begin(), v.end(), 0LL);

    for(int i = 0; i < 30; i++){
        // stores how many sub section ends with a xor sum result of 0 or 1
        vector<int> pre = {1, 0};
        int cur = 0;
        for(auto &a : v){
            cur ^= (a >> i) & 1;
            ans += pre[cur ^ 1] * 1LL << i;
            // cout << i << ": ans added: " <<  (pre[cur ^ 1] * 1LL << i) << endl;
            pre[cur]++;
        }
    }

    cout << ans << endl;
}