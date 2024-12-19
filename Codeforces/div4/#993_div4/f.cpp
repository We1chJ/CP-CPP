#include "bits/stdc++.h"

using ll = long long;
using namespace std;

int main(){
    cin.tie(0)->sync_with_stdio(0);

    int n, m, q;
    cin >> n >> m >> q;

    vector<int> a(n), b(m);
    ll suma = 0, sumb = 0;
    for(int i = 0 ; i < n; i++){
        cin >> a[i];
        suma += a[i];
    }
    for(int i = 0 ; i < m; i++){
        cin >> b[i];
        sumb += b[i];
    }

    set<ll> fa, fb;
    for(int i = 0; i < n; i++){
        fa.insert(suma-a[i]);
    }
    
     for(int i = 0; i < m; i++){
        fb.insert(sumb - b[i]);
    }

    for(int i = 0; i < q; i++){
        ll x;
        cin >> x;
        bool found = false;
        for(int num = 1; num*num <= abs(x); num++){

            if(x%num == 0 && num*(x/num) == x){
                if((fa.count(num) && fb.count(x/num)) || (fb.count(num) && fa.count(x/num))){
                    found = true;
                    break;
                }
                num *= -1;
                if((fa.count(num) && fb.count(x/num)) || (fb.count(num) && fa.count(x/num))){
                    found = true;
                    break;
                }
                num *= -1;
            }
        }
        cout << (found ? "YES" : "NO") << endl;
    }
}