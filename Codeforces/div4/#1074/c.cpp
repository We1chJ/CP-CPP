#include "bits/stdc++.h"

using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<int> v(n);
        for(int i = 0; i < n; i++){
            cin >> v[i];
        }
        unordered_set<int> s(v.begin(), v.end());
        vector<int> vn (s.begin(), s.end());
        sort(vn.begin(), vn.end());
        int ans = 1;
        int cnt = 1;
        n = vn.size();
        for(int i =1; i < n; i++){
            if(vn[i] == vn[i-1] + 1){
                cnt++;
            }else{
                cnt = 1;
            }
            ans = max(ans, cnt);
        }

        cout << ans << endl;
    }


}