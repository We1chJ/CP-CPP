#include "bits/stdc++.h"

using namespace std;

int main(){

    cin.tie()->sync_with_stdio(0);

    int n;
    cin >> n;
    vector<int> bonus(n);
    for(int i = 0; i <n;i++){
        cin >> bonus[i];
    }
    vector<int> num(n);
    for(int i = 0; i <n;i++){
        cin >> num[i];
    }

    double ans = 0.0;
    for(int b = 1; b <  ( 1 << (n)); b++){
        long long total = 0;
        double cnt = __popcount(b);
        for(int i = 0 ; i < n; i++){
            if(b & (1<<i)){
                total += num[i];
            }
        }
        // cout << total << " " << b << " " << cnt << " " << bonus[cnt-1]<< endl;
        total += bonus[cnt-1];
        double temp = total;
        ans = max(ans, temp / cnt);
    }

    cout << setprecision(100) << ans << endl;

}