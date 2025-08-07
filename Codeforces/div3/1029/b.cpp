#include "bits/stdc++.h"

using namespace std;
using ll = long long;

int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<int> v(n);
        int cnt = 1;
        for(int i = 0; i < n/2; i++){
            v[i] = cnt++;
            v[n - i -1] = cnt++;
        }
        if(n%2 == 1){
            v[n/2] = cnt;
        }

        for(auto x : v) cout << x << " ";
        cout << endl;
    }
}