#include "bits/stdc++.h"

using namespace std;

int main(){
    cin.tie(0)->sync_with_stdio(0);

    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        
        vector<int> arr(n);
        int mx = -1;
        int cnt = 0;
        for(int i = 0; i < n; i++){
            cin >> arr[i];
            if(arr[i] == mx)
                cnt++;
            else if(arr[i] > mx){
                mx = arr[i];
                cnt = 1;
            }
        }
        sort(arr.begin(), arr.end(), greater<int>());
        if(cnt != n){
            cout << "YES" << endl;
            for(int i = cnt-1; i < n; i++)
                cout << arr[i] << " ";
            for(int i = 0; i < cnt-1; i++)
                cout << mx << " ";
                cout << endl;
            
        }else
            cout << "NO" << endl;
        
    }
}