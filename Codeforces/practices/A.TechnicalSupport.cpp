#include "bits/stdc++.h"

using namespace std;

int main(){
    cin.tie(0)->sync_with_stdio(0);

    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        string str;
        cin >> str;
        int q = 0;
        for(int i = 0 ; i < n; i++){
            if(str[i] == 'Q') q++;
            else{ q = max(q-1, 0);}
        }
        if(q == 0) cout << "Yes" << endl;
        else cout << "No" << endl;
    }
}