#include "bits/stdc++.h"

using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<int> v(n);
        int mx = 0;
        for(int i = 0; i < n; i++){
            cin >> v[i];
            mx = max(mx, v[i]);
        }

        cout << v.size() * mx << endl;

    }


}