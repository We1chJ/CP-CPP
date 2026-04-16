#include "bits/stdc++.h"

using namespace std;
using ll = long long;

int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        bool decreasing = false;
        vector<int> v(n);
        for(int i = 0 ; i < n; i++){
            cin >> v[i];
        }

        for(int i = 1; i < n; i++){
            if(v[i] < v[i-1]){
                decreasing = true;
                break;
            }
        }
        if(decreasing){
            cout << 1 << endl;
        }else{
            cout << v.size() << endl;
        }

    }
}