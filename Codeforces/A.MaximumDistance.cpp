#include "bits/stdc++.h"

using namespace std;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int n ;
    cin >> n;
    long long ans = 0;
    int x[n], y[n];
    for(int i = 0; i < n; i++){
        cin >> x[i];
    }
    for(int i = 0; i < n; i++)
        cin >> y[i];

    for(int i = 0; i < n; i++){
        for(int j =0 ; j < n; j++){
            ans = max(ans, (long long)(x[i] - x[j])*(x[i] - x[j]) + (y[i] - y[j])*(y[i] - y[j]));
        }
    }
    cout << ans << '\n';
}