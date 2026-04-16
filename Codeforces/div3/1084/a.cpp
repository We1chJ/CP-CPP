#include "bits/stdc++.h"

using namespace std;
using ll = long long;

int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        int mx = -1;
        int cnt = 0;
        for(int i = 0; i < n; i++){
            int a ;
             cin >> a;
            if(a > mx) {
                mx = a;
                cnt = 1;
            }else if(a == mx){
                cnt++;
            }
        }

        cout << cnt << endl;
    }
}