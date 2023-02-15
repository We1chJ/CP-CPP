#include "bits/stdc++.h"
using namespace std;

using ll = long long;
int n;
ll m;

ll curFla = 0;

int st[200002];

void update(int pos, int val){
    pos += n;
    st[pos] += val;
    for(pos /= 2; pos >= 1; pos /=2){
        st[pos] = max(st[pos*2], st[pos*2+1]);
    }
}

int query(int a, int b){
    a += n;
    b += n;
    
    int res = 0;
    while(a <= b){
        if(a %2 == 1) res = max(res, st[a++]);
        if(b %2 == 0) res = max(res, st[b--]);
        a /= 2;
        b /= 2;
    }

    return res;
}


vector<int> fla(100001), spi(100001);

int main(){
    freopen("hayfeast.in", "r", stdin);
    freopen("hayfeast.out", "w", stdout);
    cin.tie(0)->sync_with_stdio(0);

    cin >> n >> m;
    for(int i = 1; i <= n; i ++){
        cin >> fla[i] >> spi[i];
        update(i, spi[i]);
    }
    int l = 1, r = 1;
    ll ans = INT64_MAX;
    while(r <= n){
        while(r <= n && curFla < m){
            curFla += fla[r];
            r++;
        }
        while(l <= r && curFla - fla[l] >= m){
            curFla -= fla[l];
            l++;
        }
        ans = min(ans, (ll)query(l, r));
        curFla -= fla[l];
        l++;
    }
    cout << ans << endl;
}