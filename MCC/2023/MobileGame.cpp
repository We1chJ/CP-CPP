// greedy

#include "bits/stdc++.h"
using namespace std;

int main(){

    freopen("2-mobile-game/input10.txt", "r", stdin);
    int t;
    cin >> t;
    for(int _ = 0; _ < t; _++){
        int n, a, b;
        cin >> n >> a >> b;
        multiset<int> v;
        for(int i = 0; i < n; i++){
            int num;
            cin >> num;
            v.insert(num);
        }

        int cnt = 0;
        // cout << n <<  v.size() << endl;
        while(a < b){
            if(v.empty() || *v.begin() > a){
                cnt = -1;
                break;
            }else{
                auto it = --v.lower_bound(a);
                a += *it;
                v.erase(it);
                cnt++;
            }         
            // cout << cnt << endl;   
        }
        cout << cnt << endl;
    }
}