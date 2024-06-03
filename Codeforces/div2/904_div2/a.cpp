#include "bits/stdc++.h"

using namespace std;

int main(){
    cin.tie(0) -> sync_with_stdio(0);
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >>n;
        map<int, int> freq;
        for(int i = 0 ; i< n ; i++){
            int a ;
            cin >> a;
            freq[a]++;
        }

        int ans = 0;
        for(auto a : freq){
            ans += a.second / 3;
        }

        cout << ans << endl;
    }

}