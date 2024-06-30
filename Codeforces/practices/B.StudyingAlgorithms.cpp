#include "bits/stdc++.h"

using namespace std;

int main(){
    cin.tie(0)->sync_with_stdio(0);

    int n, x;
    cin >> n >> x;
    vector<int> v(n);
    for(int i = 0; i < n; i ++){
        cin >> v[i];
    }
    sort(v.begin(), v.end());
    int ans = 0;
    for(auto & a : v){
        if(a <= x){
            ans++;
            x -= a;
        }else
            break;
    }
    cout << ans << endl;
}