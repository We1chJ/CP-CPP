#include "bits/stdc++.h"

using namespace std;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int t;
    cin >> t;
    while(t--){
        int n ;
        cin >> n;
        vector<int> a(n);
        for(int i = 0; i < n; i++){
            cin >> a[i];
        }
        vector<int> b(n);
        for(int i = 0; i < n; i++){
            cin >> b[i];
        }
        int m;
        cin >> m;
        vector<int> d(m);
        for(int i = 0; i < m; i++){
            cin >> d[i];
        }

        multiset<int> s;
        for(int i = 0; i < n; i ++){
            if(a[i] != b[i])
                s.insert(b[i]);
        }

        bool last = false;
        for(auto& num: b){
            if(d[m-1] == num){
                last = true;
                break;
            }
        }
        if(!last){
            cout << "NO" << endl;
            continue;
        }

        multiset<int> ds (d.begin(), d.end());
        for(auto& x : s){
            if(ds.count(x)){
                ds.erase(ds.find(x));
            }else{
                cout << "NO" << endl;
                goto end;
            }
        }
        cout << "YES" << endl;

        end: ;
    }
}