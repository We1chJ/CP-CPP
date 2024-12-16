#include "bits/stdc++.h"
using ll = long long;
using namespace std;

int main(){
    cin.tie(0)->sync_with_stdio(0);

    int t;
    cin >> t;
    while(t--){
        string s;
        cin >>s;
        reverse(s.begin(), s.end());
        for(int i =0 ; i < s.length(); i++){
            if(s[i] == 'p')
                s[i] = 'q';
            else if(s[i] == 'q')
                s[i] = 'p';
        }
        cout << s << endl;
    }
}