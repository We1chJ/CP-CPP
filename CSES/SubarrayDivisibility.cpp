#include "bits/stdc++.h"
using namespace std;
using ll = long long;
int main(){
    cin.tie(0)->sync_with_stdio(0);

    int n;
    cin >> n;
    vector<int> v(n);
    for(int i = 0; i<n; i++){
        cin >> v[i];
        v[i] %= n;
    }
    ll ans = 0;
    map<int, int> cnt;
    int cur= 0 ;
    for(int i = 0; i <n ;i++){
        cur += v[i];
        cur %= n;

        int inv = cur > 0 ? (cur - n) : (cur + n);
        if(cur == 0){
            ans += cnt[0]+1;
        }else if(cnt[cur] != 0 || cnt[inv] != 0){
            ans += cnt[cur] + cnt[inv];
        }
        cnt[cur]++;
    }
    
    cout << ans << endl;
}