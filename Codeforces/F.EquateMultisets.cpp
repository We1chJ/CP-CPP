#include "bits/stdc++.h"
using namespace std;

int main(){
    cin.tie(0) -> sync_with_stdio(0);

    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        multiset<int> a, b;
        for(int i = 0; i < n; i++) {
            int x; cin >> x;
            while (x % 2 == 0) {
                x /= 2;
            }
            a.insert(x);
        }

        for(int i = 0; i < n; i++){
            int x; cin >> x;
            b.insert(x);
        }

        while(!b.empty()){
            int x = *b.rbegin();
            if(a.count(x)){
                b.erase(b.find(x));
                a.erase(a.find(x));
            } else{
                if(x == 1) break;
                b.erase(b.find(x));
                b.insert(x/2);
            }
        }

        cout << (b.empty() ? "YES" : "NO" ) << endl;
    }
}