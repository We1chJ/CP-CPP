#include "bits/stdc++.h"

using namespace std;


int main(){
    int t;
    cin >> t;
    while(t--){
        int n, k;
        cin >> n >> k;
        vector<int> a(n), b(n);
        int s = k, l = -1;
        for(int i = 0; i < n; i++){
            cin >> a[i];
        }
        for(int i  = 0; i < n; i++){
            cin >> b[i];
        }

        for(int i = 0 ; i< n; i++){
            if(b[i] == -1){
                s = min(s, a[i]);
                l = max(l, a[i]);
            }
        }

        int ans = 0;
        int x = -1;
        for(int i =0 ; i < n; i++){
            if(b[i] == -1) continue;
            if(a[i] + b[i] != x){
                if(x == -1){
                    x = a[i] + b[i];
                }else{
                    ans = -1;
                    break;
                }
            }
        }
        if(ans == -1){
            cout << 0 << endl;
            continue;
        }

        if(x == -1){
            // all are -1
            ans = s + k - l + 1;
        }else{
            ans = k;
            for(int i = 0 ; i < n; i++){
                if(a[i] > x || b[i] > x || x - a[i] > k){
                    ans = -1;
                    break;
                }
            }
            if(ans == -1){
                cout << 0 << endl;
                continue;
            }
            ans = 1;
        }
        cout << ans << endl;
    }
}