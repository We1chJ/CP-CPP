#include "bits/stdc++.h"
using namespace std;

int main(){

    int t;
    cin >> t;
    while(t--){
        int x, y, k;
        cin >> x >> y >> k;
        if(x == 0 && y == 0){
            cout << 0 << endl;
            continue;
        }

        int xt = x / k;
        int yt = y / k;
        if(x%k) xt ++;
        if(y%k) yt ++;
        
        // xt can be 1 more than yt because the jumping starts with x first and can ends with x
        if(xt > yt +1){
            // needs more empty y direction moves to fill up place
            // just up to xt-1 is good enough
            yt = xt-1;
        }
        // when xt is less than yt, xt needs to be up to yt to work
        else if(xt < yt){
            xt = yt;
        }
        cout << xt + yt << endl;
        
    }
}