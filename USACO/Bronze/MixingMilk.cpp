#include "bits/stdc++.h"

using namespace std;

int main(){
    freopen("mixmilk.in", "r", stdin);
    freopen("mixmilk.out", "w", stdout);
    cin.tie(0)->sync_with_stdio(0);
    int c[3], cur[3];
    for(int i = 0; i < 3; i++)
        cin >> c[i] >> cur[i];
    
    for(int i = 0 ; i < 100; i++){
        int a = i%3;
        int b = (a+1)%3;
        
        int amt = min(cur[a], c[b] - cur[b]);
        cur[b] += amt;
        cur[a] -= amt;
    }
    for(int i = 0; i < 3; i++)
        cout << cur[i] << '\n';
    
}