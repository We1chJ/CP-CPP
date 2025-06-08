#include "bits/stdc++.h"

using namespace std;
using ll = long long;

int main(){
    int t;
    cin >> t;
    while(t--){
        int n, x;
        cin >> n >> x;
        vector<int> v(n);
        for(int i = 0; i < n; i++){
            cin >> v[i];
        }
        int i1 = -1, i2 = -1;
        for(int i = 0; i < n; i++){
            if(v[i] == 1){
                i1 = i;
                break;
            }
        }
        for(int i = n-1; i>=0; i--){
            if(v[i] == 1){
                i2 = i;
                break;
            }
        }

        if(i2 - i1 + 1 <= x){
            cout << "YES" << endl;
        }else{
            cout << "NO" << endl;
        }


    }
}