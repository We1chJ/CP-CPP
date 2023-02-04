#include "bits/stdc++.h"

using namespace std;

int n;

int bit[50000*2];

void update(int pos, int val){
    while(pos <= 2*n){
        bit[pos] += val;
        pos += pos & -pos;
    }
}

int query(int a){
    int sum = 0;
    while(a > 0){
        sum += bit[a];
        a -= a & -a;
    }
    return sum;
}


int main(){
    freopen("circlecross.in", "r", stdin);
    freopen("circlecross.out", "w", stdout);
    cin.tie(0)->sync_with_stdio(0);
    cin >> n;
    vector<pair<int, int>> v(n, make_pair(-1, -1));
    for(int i = 0 ; i < 2*n; i++){
        int a;
        cin >> a;
        a--;
        if(v[a].first == -1)
            v[a].first = i;
        else
            v[a].second = i;
    }
    sort(v.begin(), v.end());

    int ans = 0;
    for(auto a : v){
        int fir = a.first;
        int sec = a.second;
        ans += query(sec) - query(fir);
        update(sec, 1);
    }
    cout << ans << endl;   
}