#include "bits/stdc++.h"
using namespace std;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int t ;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<int> v(n);
        int total = 0;
        for(int i = 0; i < n; i++){
            cin >> v[i];
            if(i > 0){
                total += abs(v[i]-v[i-1]);
            }
        }
        
        int ans = min(total - abs(v[1]-v[0]), total - abs(v[n-1]-v[n-2]));

        for(int i = 1; i < n-1; i++){
            ans = min(ans, total - abs(v[i]-v[i-1]) - abs(v[i+1]-v[i]) + abs(v[i+1] - v[i-1]));
        }

        cout << ans << endl;


    }
}