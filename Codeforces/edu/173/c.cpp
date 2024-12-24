#include "bits/stdc++.h"

using namespace std;
using ll = long long;

int main(){
    cin.tie(0) -> sync_with_stdio(0);
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<int> v(n);
        int xpos = 0;
        for(int i =0 ; i < n; i++){
            cin >> v[i];
            if(v[i] != 1 && v[i] != -1)
                xpos = i;
        }

        int maxl = 0;
        int num = 0;
        for(int i =0 ; i < xpos; i++){
            num += v[i];
            
        }


    }
}