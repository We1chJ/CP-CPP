#include "bits/stdc++.h"

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int x1, x2, y1, y2;
    cin >> x1 >> y1 >> x2 >> y2;
    // results in 1-3

    int ans = 0;
    int xdis = abs(x1-x2);
    int ydis = abs(y1-y2);

    if(xdis < ydis) swap(xdis, ydis); 
    if(xdis == ydis) ans = 1;
    else if((xdis + ydis)%2 == 0)ans = 2;
    else if(xdis <= 2 && ydis <= 2) ans = 1;
    else if(abs((xdis + 1)/2 - xdis) <= 2 && abs((xdis + 1)/2 - ydis) <= 2) ans = 2;
    else ans = 3;

    

    cout << ans << endl;
    
    return 0;
}
