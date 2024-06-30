#include "bits/stdc++.h"
using namespace std;

int main(){
    cin.tie(0) -> sync_with_stdio(0);

    int t;
    cin >> t; 
    while(t--){
        int n ;
        cin >> n;
        vector<int> v (n);
        for(int i = 0 ; i <n ; i++){
            cin >> v[i];
        }

        int ans = 0;
        vector<int> vi (3);
        for(int i = 0; i < n-2; i++){
            vi[0] = v[i];
            vi[1] = v[i+1];
            vi[2] = v[i+2];
            sort(vi.begin(), vi.end());
            ans = max(ans, vi[1]);
        }
        if(n == 2){
            ans = min(v[0], v[1]);
        }
        cout << ans << endl;
    }
}