#include "bits/stdc++.h"

using namespace std;

using ll = long long;


int main(){
    freopen("3-innovation/input7.txt", "r", stdin);
    int n, m;
    cin >> n >> m;

    vector<pair<ll, ll>> v (n);
    for(int i = 0; i < n ;i++){
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        v[i] = {(ll)a + b, (ll) c+ d};        
    }
    
    sort(v.begin(), v.end(), [](const pair<ll,ll> &a, const pair<ll, ll> &b) {return a.first > b.first;});
    ll sum = 0;
    for(int i = 0 ;i < m; i++){
        sum += v[i].first;
    } 
    ll base = sum;
    for(int i = 0; i < n; i++){
        if(i < m){
            sum = max(sum, base + v[i].second);
        }else{
            sum = max(sum, base + v[i].first + v[i].second - v[m-1].first);
        }
    }
    cout << sum << endl;
    
}