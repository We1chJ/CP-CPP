#include "bits/stdc++.h"

using namespace std;

int main(){

    cin.tie(0) -> sync_with_stdio(0);

    int t;
    cin >> t;
    for(int a = 0; a < t; a++){
        int n;
        cin >> n;
        string s;
        cin >> s;
        bool arr[26] = {};
        int ans = 0;
        for(int i = 0; i < s.size(); i++){
            if(arr[s[i] - 65] == false) {
                ans += 2;
                arr[s[i] - 65] = true;

            }else 
                ans++;
        }
        cout << ans << endl;
    }
}