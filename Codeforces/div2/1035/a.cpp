#include "bits/stdc++.h"
using namespace std;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int t;
    cin >> t;
    while(t--){
        int a, b, x, y;
        cin >> a >> b >> x >> y;
        int cnt =0 ;
        while(a < b){
            if(a & 1){
                cnt += x;
                a++;
            }else{
                cnt += min(x, y);
                a ++;
            }
        }
        if(a-1 == b && (a & 1)){
            cout << y << endl;
            continue;
        }
        if(a > b){
            cout << -1 << endl;
            continue;
        } 
        cout << cnt << endl;
    }
}