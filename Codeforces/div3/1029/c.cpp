#include "bits/stdc++.h"

using namespace std;
using ll = long long;

int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<int> v(n);
        
        vector<int> freq (n+1, 0);
        for(int i = 0; i < n; i++){
            cin >> v[i];
            freq[v[i]] ++;
        }

        int l = 0, r = n;
        while(l < r){
            int mid = (l+r+1)/2;
            int segCnt = 0;
            vector<int> f = freq;
            set<int> prev;
            set<int> cur;
            bool success = true;
            for(int i = 0; i< n; i++){
                if(segCnt >= mid){
                    success = false;
                    break;
                }
                if(i != 0 && f[v[i]] < mid - segCnt){
                    if (!includes(cur.begin(), cur.end(), prev.begin(), prev.end()) || cur.size() < prev.size()){
                        success = false;
                        break;
                    }
                    prev = cur;
                    cur.clear();
                    segCnt ++; //switch 
                }
                cur.insert(v[i]);
                f[v[i]]--;
            }
            if (!includes(cur.begin(), cur.end(), prev.begin(), prev.end()) || cur.size() < prev.size()){
                success = false;
            }

            if(success){
                l = mid;
            }else{
                r = mid-1;
            }
        }
        cout << l << endl;        
    }
}