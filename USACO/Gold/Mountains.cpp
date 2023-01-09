#include"bits/stdc++.h"
using namespace std;
using ll = long long;
using pi = pair<ll, ll>;

ll mount[2001];
set<int> rig[2001];


bool comp(int ind, int i1, int i2) {
    // does index i2 to ind have a greater slope than index i1 to ind
    int d1 = abs(ind - i1), d2 = abs(ind - i2);
    ll h1 = mount[i1] - mount[ind], h2 = mount[i2] - mount[ind];
    return h2 * d1 >= h1 * d2;
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int n ;
    cin >> n;
    for(int i = 1;i <= n  ;i ++){
        cin >> mount[i];
    }
    for(int i = 1; i <= n; i++){
        for(int j = i+1;j <= n; j++){
            if (rig[i].empty())
                rig[i].insert(j);
            else
                if(comp(i, *rig[i].rbegin(), j))
                    rig[i].insert(j);
        }
    }
    int ans = 0;

    for(int i = 1; i <= n; i++) ans += (int)rig[i].size();
    int q;
    cin >> q;
    for(int i = 0 ; i <q ; i++){
        int x, y;
        cin >> x >> y;
        mount[x] += y;

        // left of a;
        for (int j = 1; j <= x - 1; j++) {
            auto it = rig[j].lower_bound(x);
            bool add = false;
            if ((*it) == x) {
                add = true;
                it++;
            } else {
                --it;
                if (comp(j, (*it), x)) {
                    rig[j].insert(x);
                    ans++;
                    add = true;
                    it++;
                    it++;
                }
            }
            if (add) {
                while (it != rig[j].end() && !comp(j, x, (*it))) {
                    it = rig[j].erase(it);
                    ans--;
                }
            }
        }

        // update the set for x
        ans -= (int)rig[x].size();
        rig[x].clear();
        for (int j = x + 1; j <= n; j++) {
            if (rig[x].empty()) {
                rig[x].insert(j);
                ans++;
            } else {
                if (comp(x, *rig[x].rbegin(), j)) {
                    rig[x].insert(j);
                    ans++;
                }
            }
        }

        cout << ans << endl;
    }
    
    
}
