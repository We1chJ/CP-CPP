#include "bits/stdc++.h"

using namespace std;

int main(){
    cin.tie(0)->sync_with_stdio(0);

    int n, m, q;
    cin >> n >> m >> q;

    vector<int> a(n), b(m);
    int suma = 0, sumb = 0;
    for(int i = 0 ; i < n; i++){
        cin >> a[i];
        suma += a[i];
    }
    for(int i = 0 ; i < m; i++){
        cin >> b[i];
        sumb += b[i];
    }

    vector<int> fa, fb;
    for(auto & numa: a){
        fa.push_back(suma - numa);
    }
    
    for(auto & numb: b){
        fb.push_back(sumb - numb);
    }
    
    sort(fa.begin(), fa.end());
    sort(fb.begin(), fb.end());

    for(int i = 0; i < q; i++){
        int x;
        cin >> x;
        bool isFound = false;
        int sqrt_x = sqrt(abs(x));
        
        auto sta = lower_bound(fa.begin(), fa.end(), -sqrt_x);
        while(sta != fa.end() && abs(*sta) <= sqrt_x){
            int num = *sta;
            if(num != 0 && x%num == 0 && (lower_bound(fb.begin(), fb.end(), x/num) != fb.end()) && *lower_bound(fb.begin(), fb.end(), x/num) == x/num){
                isFound = true;
                break;
            }
            sta++;
        }

        auto stb = lower_bound(fb.begin(), fb.end(), -sqrt_x);
        
        while(stb != fb.end() && abs(*stb) <= sqrt_x){
            int num = *stb;
            if(num != 0 && x%num == 0 && lower_bound(fa.begin(), fa.end(), x/num) != fa.end() && *lower_bound(fa.begin(), fa.end(), x/num) == x/num){
                isFound = true;
                break;
            }
            stb++;
        }
        cout << (isFound ? "YES" : "NO") << endl;
    }
}