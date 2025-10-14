#include "bits/stdc++.h"

using namespace std;

int main(){

    cin.tie()->sync_with_stdio(0);

    int r, g, b, cr, cg, cb, crg, cgb;
    cin >> r >> g >> b >> cr >> cg >> cb >> crg >> cgb;
    
    int needr = r - cr;
    int needg =  g - cg;
    int needb =  b - cb;

    int ans = 0;
    if(needr > 0){
        int amt = min(crg, needr);
        needr -= amt;
        crg -= amt;
        ans += amt;
    }

    if(needb > 0){
        int amt = min(cgb, needb);
        cgb -= amt;
        ans += amt;
        needb -= amt;
    }

    if(needg > 0){
        if(cgb + crg >= needg){
            ans += needg;
        }else{
            ans = -1;
        }
    }
    if(needb > 0  || needr > 0) ans = -1;
    cout << ans << endl;
}