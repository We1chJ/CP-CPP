// greedy, binary search
#include "bits/stdc++.h"

using namespace std;

int main(){
    freopen("4-tichu/input5.txt", "r", stdin);

    cin.tie(0)->sync_with_stdio(0);
    int n, k;
    cin >> n >> k;
    set<int> s;
    for(int i = 0; i <n -k; i++){
        int num;
        cin >> num;
        s.insert(num);
    }

    vector<int> v;
    for(auto a : s)
        v.push_back(a);
    
    
    int ans = k;
    for(int i = 0; i < v.size(); i++){
        int l = i, r = v.size()-1;
        while(l < r){
            int mid = (l+r+1)/2;
            // num dis - num present <= k
            if(v[mid] - v[i] + 1 - (mid - i + 1) <= k){
                l = mid;
            }else{
                r = mid-1;
            }
        }
        ans = max(ans, (l-i+1) + k);
    }
    cout << ans << endl;
        
}