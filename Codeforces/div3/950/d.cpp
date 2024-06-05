#include "bits/stdc++.h"

using namespace std;

int gcd(int a, int b){
    if(b == 0)
        return a;
    return gcd(b, a%b);
}

int main(){
    cin.tie(0)->sync_with_stdio(0);

    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<int> v(n);
        for(int i = 0; i < n; i++){
            cin >> v[i];
        }
        vector<int> g(n-1);
        for (int i = 0; i < n-1; i++){
            g[i] = gcd(v[i], v[i+1]);
        }

        bool used = false;
        bool suc = false;
        for(int i = 0; i < n-2;  i++){
            if(g[i] > g[i+1]){
                if(used){
                    goto no;
                    break;
                }else{
                    if(i == n-3)
                        used = true;
                }
                int res = gcd(v[i], v[i+2]);
                if(i == 0){
                    if(res <= g[i+2]){
                        used = true;
                        i++;
                    }
                }else if(i < n - 3){
                    if(res >= g[i-1] && res <= g[i+2]){
                        used = true;
                        i++;
                    }
                }else{
                    if(res >= g[i-1]){
                        used = true;
                        i++;
                    }
                }
                if(!used)
                    goto no;
            }
        }
        
        if(!used){
            if(g.size() == 2)
                suc = true;
            for(int i = 0; i < n-2;  i++){
                int res = gcd(v[i], v[i+2]);
                if(i == 0){
                    if(res <= g[i+2]){
                        suc = true;
                        break;
                    }
                }else if(i < n - 3){
                    if(res >= g[i-1] && res <= g[i+2]){
                        suc = true;
                        break;
                    }
                }else{
                    if(res >= g[i-1]){
                        suc = true;
                        break;
                    }
                }
            }
            if(suc)
                cout << "YES" << endl;
            else
            no: cout << "NO" << endl;
        }else{
            cout << "YES" << endl;
        }
        

    }

}