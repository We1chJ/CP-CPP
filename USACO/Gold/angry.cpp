#include "bits/stdc++.h"

using namespace std;

using ll = long long;

int n;
set<ll> pos;

bool validLeft(ll r, ll x){
    auto nxt = pos.lower_bound(x-r);
    if(nxt == pos.end()) return false;
    
    while(nxt != pos.begin()){
        r -= 2;
        auto t = pos.lower_bound(*nxt - r);
        if(t == nxt && t != pos.begin()) return false;
        nxt = t;
    }
    return true;
}

bool validRight(ll r, ll x){
    auto nxt = --pos.upper_bound(x+r);
    
    while(nxt != --pos.end()){
        r -= 2;
        auto t = --pos.upper_bound(*nxt + r);
        if(t == nxt && t != --pos.end()) return false;
        nxt = t;
    }
    return true;
}

int main(){

    freopen("angry.in", "r", stdin);
    freopen("angry.out", "w", stdout);

    cin >> n;

    for(int i = 0; i < n; i++){
        int num;
        cin >> num;
        pos.insert(2*num);
    }

    ll rl = 0;
    ll rr = 1000000000;

    while(rl < rr){
        ll rmid = (rl + rr)/2;
        ll posl = *pos.begin();
        ll posr = *(--pos.end());
        while(posl < posr){
            ll posmid = (posl+posr+1) /2;
            if(validLeft(rmid, posmid)){
                posl = posmid;
            }else {
                posr = posmid-1;
            }
        }
        if(validRight(rmid, posl)){
            rr = rmid;
        }else {
            rl = rmid + 1;
        }
    }
    cout << rl/2 << "." << ((rl%2 == 0) ? "0" : "5") << endl;
}