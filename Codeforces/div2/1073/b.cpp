#include "bits/stdc++.h"

using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<int> v (n);
        for(int i= 0; i <n ;i++){
            cin >> v[i];
        }
        sort(v.begin(), v.end());
        bool ans = true;
        for(int i = 0; i < n-1; i++){
            int mex1 = 0;
            for(int j = 0; j <= i; j++){
                if(mex1 == v[j]) mex1++;
            }
            int mex2 = 0;
            for(int j = i+1; j < n; j++){
                if(mex2 == v[j]) mex2++;
            }

            if(mex1 == mex2){
                ans = false;
                break;
            }
        }
        
        cout << (ans ? "YES" : "NO") << endl;

    }
}