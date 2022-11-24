#include "bits/stdc++.h"

using namespace std;

int arr[51];
int main(){
    cin.tie(0)->sync_with_stdio(0);

    int t;
    cin >> t;
    while(t--){
        int n, s;
        cin >> n >> s;
        int maxNum = 0;
        int cur = 0;
        for(int i = 0 ; i < n ;i++){
            cin >> arr[i];
            maxNum = max(maxNum, arr[i]);
            cur += arr[i];
        }
        int sum = (maxNum + 1)* maxNum / 2;
        if(sum - cur <= s){
            s -= sum - cur;
            while(s > 0) s -= ++maxNum;
            if(s < 0) cout << "NO" << endl;
            else cout << "YES" << endl;
        } else
            cout << "NO" << endl;
    }
}