#include "bits/stdc++.h"

using namespace std;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int n;
    cin >> n;
    vector<pair<int, int>> v(n);
    for(int i = 0; i < n; i++){
        cin >> v[i].first >> v[i].second;
    }
    sort(v.begin(), v.end(), [](pair<int, int> a, pair<int, int> b){
        return a.second < b.second;
    });
    int ans = 0;
    int prev = 0;
    for(auto & a : v){
        if(a.first >= prev){
            ans ++;
            prev = a.second;
        }
    }
    cout << ans << endl;
}