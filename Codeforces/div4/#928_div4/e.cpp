#include "bits/stdc++.h"

using namespace std;

int main(){
    
    int t;
    cin >> t;
    while(t--){
        int n, k;
        cin >> n >> k;

        if(k <= (n+1)/2){
            cout << k*2-1 << endl;
            continue;
        }

        int exp = 1;
        while(k > (n+1)/2){
            k -= (n+1)/2;
            n -= (n+1)/2;
            exp *= 2;
        }
        // cout << k << " " << exp << "==========\n";
        cout << (k*2-1)*exp << endl;
        
    }
}