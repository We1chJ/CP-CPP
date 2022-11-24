#include "bits/stdc++.h"
using namespace std;

using ll = long long;

int main(){
    cin.tie(0)->sync_with_stdio(0);

    int t;
    cin >> t;
    while(t--){
        string str ;
        cin >> str;
        int l = str.length();
        bool good = true;
        for(int i = 0; i < l-1; i++){
            if(str[i] == 'Y' && str[i+1] != 'e'){
                good = false;
                break;
            }
            if(str[i] == 'e' && str[i+1] != 's'){
                good = false;
                break;
            }

            if(str[i] == 's' && str[i+1] != 'Y'){
                good = false;
                break;
            }
            
            if(str[i] != 'Y' && str[i] != 'e' && str[i] != 's'){
                good = false;
                break;
            }
        }
        if(str[l-1] != 'Y' && str[l-1] != 'e' && str[l-1] != 's')
                good = false;
        cout << (good ? "YES" : "NO") << endl;
    }
}