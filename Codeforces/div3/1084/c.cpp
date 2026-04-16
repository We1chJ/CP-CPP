#include "bits/stdc++.h"

using namespace std;
using ll = long long;

int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        string s;
        cin >> s;
        if(n %2 == 1) {
            cout << "NO" << endl;
            continue;
        }
        while(s.size()){
            string pre = "";
            bool edited = false;
            for(int i = 0; i < s.size()-1; i++){
                if(s[i] == s[i+1]){
                    s = pre + s.substr(i+2);
                    edited = true;
                    break;
                }
                pre += s[i];
            }
            if(edited == false){
                break;
            }
        }

        if(s.size() == 0){
            cout << "YES" << endl;
        }else{
            cout << "NO" << endl;
        }

    }
}