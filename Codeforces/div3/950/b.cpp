#include "bits/stdc++.h"
using namespace std;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int t;
    cin >> t;
    while(t--){
        int n, f, k;
        cin >> n >> f >> k;
        vector<int> v (n);
        for(int i = 0; i< n; i++){
            cin >> v[i];
        }
        int fav = v[f-1];
        sort(v.begin(), v.end(), greater<>());
        if(k == n || v[k] < fav)
            cout << "yes" << endl;
        else if(v[k] == fav && v[k-1] == fav)
            cout << "MAYBE" << endl;
        else
            cout << "no" << endl;

    }
}