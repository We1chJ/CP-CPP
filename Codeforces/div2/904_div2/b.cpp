#include "bits/stdc++.h"

using namespace std;

int main(){
    cin.tie(0) -> sync_with_stdio(0);


    int t;
    cin >> t;
    while(t--){
        int n, k;
        cin >> n >> k;

        if(n == 1){
            cout << k << endl;
            continue;
        }

        for(int i = 0; i < n-2; i++){
            cout << "0 ";
        }

        int bit = 0;
        int temp = k;

        for(int i = 0; temp >= (1 << i); i++){
            if((temp & (1 << i)))
                bit = i;
        }
        
        // cout << "|||||||" << bit << endl;
        
        cout << (1<<bit)-1 << " " << k-((1<<bit)-1) << endl; 
    }
}