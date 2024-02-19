#include "bits/stdc++.h"
using namespace std;


int main(){
    cin.tie(0)->sync_with_stdio(0);
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        multiset<int> num;
        for(int i = 0 ; i < n ;i++){
            int a;
            cin >> a;
            num.insert(a);
        }

        int ans = 0;
        while(num.size() > 0){
            auto it = num.begin();
            int a = *it;
            num.erase(it);
            // cout << (~a ^ (1 << 31)) << endl;
            if(num.lower_bound((~a ^ (1 << 31))) != num.end() && ((~a ^ (1 << 31))) == *num.lower_bound((~a ^ (1 << 31))))
                num.erase(num.lower_bound((~a ^ (1 << 31))));
            ans++;
        }
        cout << ans << endl;
        
    }
}