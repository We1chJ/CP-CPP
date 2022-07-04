#include "bits/stdc++.h"

using namespace std;

int main(){

    // cin.tie(0) -> sync_with_stdio(0);
    freopen("cardgame.in", "r", stdin);
    freopen("cardgame.out", "w", stdout);
    int n;
    vector<int> el;
    cin >> n;
    vector<int> be;
    unordered_set<int> s;
    for(int i = 0; i < n; i++){
        int a;
        cin >> a;
        el.push_back(a);
        s.insert(a);
    }
    for(int i = 1;i <= 2*n; i++){
        if(s.count(i) == 0) be.push_back(i);
    }
    vector<int> large;
    vector<int> small;
    sort(be.begin(), be.end());
    for(int i = 0; i < n/2; i++) small.push_back(be[i]);
    for(int i = n/2; i < n; i++) large.push_back(be[i]);
    int ans = 0;
    
    for(int i = 0; i < n/2; i++){
        auto up = upper_bound(large.begin(), large.end(), el[i]);
        if(up == large.end()){
            large.erase(large.begin());
            continue;
        } 
        if(*up > el[i]){ 
            ans++;
            large.erase(up);
        } else large.erase(large.begin());
    }
    for(int i = 0; i < n/2; i++){
        auto up = lower_bound(begin(small), end(small), el[i+n/2]);
        if(up != small.begin()) up --;
        if(*up < el[i+n/2]){ 
            ans++;
            small.erase(up);
        } else small.erase(small.end()-1);
    }
    cout << ans << endl;    
}