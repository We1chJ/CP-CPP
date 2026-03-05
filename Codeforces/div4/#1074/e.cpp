#include "bits/stdc++.h"

using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        int n, m, k;
        cin >> n >> m >> k;
        vector<int> robots(n);
        for(int i=0;i <n; i++){
            cin >> robots[i];
        }
        vector<int> spikes(m);
        for(int i=0;i <m; i++){
            cin >> spikes[i];
        }
        sort(robots.begin(), robots.end());
        sort(spikes.begin(), spikes.end());
        string s;
        cin >> s;
        int cur = 0;
        int mxl = INT_MAX;
        int mxr = INT_MIN;
        vector<int> left(k);
        vector<int> right(k);
        for(int i = 0; i < k; i++){
            auto c = s[i];
            if(c == 'L'){
                cur--;
            }else{
                cur++;
            }

            mxl = min(mxl, cur);
            mxr = max(mxr, cur);

            left[i] = mxl;
            right[i] = mxr;
        }


        vector<int> ans(k, 0);
        for(int i = 0 ; i <n; i ++){
            int r = robots[i];
            auto it = lower_bound(spikes.begin(), spikes.end(), r);
            int ind = INT_MAX;
            if(it != spikes.end()){
                // right side
                int dif = *it - r;
                it = lower_bound(right.begin(), right.end(), dif);
                if(it != right.end()){
                    ind = it - right.begin();
                }
            }


            it = lower_bound(spikes.begin(), spikes.end(), r);
            if(it != spikes.begin()){
                it--;
                // left side
                int dif = *it-r;
                it = upper_bound(left.begin(), left.end(), dif);
                if(left.size() > 1){
                    it--;
                    ind = min(ind, (int)(it - left.begin()));
                    cout << ind << endl;
                }
            }
            
            if(ind != INT_MAX){
                ans[ind]--;
            }
        }
        int total = 0;
        for(auto & a : ans){
            total += a;
            
            cout << n+total << " ";
        }
        cout << endl;
    }


}