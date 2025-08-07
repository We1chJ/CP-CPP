#include "bits/stdc++.h"

using namespace std;

int main(){
    cin.tie(0) -> sync_with_stdio(0);
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<int> v (n);
        vector<int> cnt(n+1);
        cnt[0] = 0;
        set<int> s;
        for(int i = 0 ; i <n ; i++){
            cin >> v[i];
            s.insert(v[i]);
            cnt[i+1] = s.size();
        }

        if(n == 1) {
            cout << 1 << endl;
            continue;
        }
        int ans = 0;

        int r = n;
        int l = r;
        while(l > 0 && r > 0){
            s.clear();
            while(l > 0 && s.size() != cnt[r]){
                s.insert(v[l-1]);
                l--;
            }
            ans++;
            r = l;
        }

        cout << ans << endl;
    }
}