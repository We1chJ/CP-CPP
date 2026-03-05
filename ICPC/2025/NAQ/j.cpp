#include "bits/stdc++.h"

using namespace std;

int main(){

    cin.tie()->sync_with_stdio(0);
    vector<int> num(100);
    for(int i = 0; i < 100; i++){
        cin >> num[i];
    }
    int ans = num[99]%10 ;
    if(ans == 0) ans = 10;
    cout << ans << endl;
}