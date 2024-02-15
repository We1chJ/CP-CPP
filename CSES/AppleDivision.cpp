#include "bits/stdc++.h"
using namespace std;

int main(){
    cin.tie(0) -> sync_with_stdio(0);
    int n;
    cin >> n;
    vector<int> num (n);
    long long sum = 0;
    for(int i = 0; i < n; i ++){
        cin >> num[i];
        sum += num[i];
    }

    long long ans = INT64_MAX;
    for(int b = 0; b < (1 << n); b++){
        long long cur = 0;
        for(int i = 0; i < n; i++){
            if(b&(1 << i)) cur += num[i];
        }
        ans = min(ans, abs(sum - cur - cur));
    }
    cout << ans << '\n';
}