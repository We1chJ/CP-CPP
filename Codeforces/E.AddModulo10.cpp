#include "bits/stdc++.h"

using namespace std;

vector<int> arr(200001);

int main(){

    cin.tie(0) -> sync_with_stdio(0);
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        int cnt = 0;
        for(int i = 0; i < n;i++){
            cin >> arr[i];
            if(arr[i]%10 == 0 || arr[i]%10 == 5)
                cnt++;
            else while(arr[i]%10 != 2)
                arr[i] += arr[i]%10;
        }
        if(cnt != n && cnt != 0) cout << "NO" << endl;
        else if(cnt == n){
            arr[0] += arr[0]%10;
            int num = arr[0];
            bool ok = true;
            for(int i =1 ; i < n ;i ++){
                arr[i] += arr[i]%10;
                if(arr[i] != num) ok = false;
            }
            if(ok) cout << "YES" << endl;
            else cout << "NO" << endl;
        }else{
            bool done = false;
            for(int i = 1; i < n ;i ++){
                if(abs(arr[i] - arr[i-1])%20 != 0){
                    done = true;
                    break;
                }
            }
            if(done) cout << "NO" << endl;
            else cout << "YES" << endl;
        }
    }
}