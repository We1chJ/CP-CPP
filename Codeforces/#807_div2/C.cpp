#include "bits/stdc++.h"

using namespace std;

using ll = long long;
int main(){
    cin.tie(0) -> sync_with_stdio(0);

    int t;
    cin >> t;
    for(int _ = 0; _ < t; _++){
        int n, c, q;
        cin >> n >> c >> q;
        string s;
        cin >> s;
        vector<ll> left(c+1), right(c+1), dif(c+1);
        left[0] = 0;
        right[0] = n;

        for(int i = 1; i <= c; i ++){
            ll a, b;
            cin >> a >> b;
            a--; b--;
            left[i] = right[i-1];
            right[i] = left[i] + b - a +1;
            dif[i] = left[i] - a;
        }

        while(q--){
            ll k;
            cin >> k;
            k--;
            for(int i = c; i >= 1; i--){
                if(k < left[i]) continue;
                else k -= dif[i];
            }
            cout << s[k] << endl;
        }
        
    } 
}