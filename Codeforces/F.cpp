#include "bits/stdc++.h"

using namespace std;

int main(){

    cin.tie(0) -> sync_with_stdio(0);

    int t;
    cin >> t;
    for(int a = 0; a < t; a++){
        int n;
        cin >> n;
        vector<pair<int, int>> v;
        for(int i = 0; i < n ;i ++){
            int num;
            cin >> num;
            if(num < i+1) v.push_back({num, i+1});
        }
        sort(v.begin(), v.end());
        long long ans = 0;
        for(int i = 0; i < v.size(); i++){
            auto num = v[i];
            int val = num.first;
            int ind = num.second;
            int l = i + 1;
            int r = v.size();
            while(l < r){
                int mid = (l + r) /2;
                if(v[mid].first > ind) r = mid;
                else l = mid + 1;
            }
            ans += v.size() - l;
        }
        cout << ans << endl;
    }
}