#include "bits/stdc++.h"

using namespace std;

using ll = long long;

struct Edge{
    int a, b, dif;
};
auto cmp = [](const Edge& a, const Edge& b){ return a.dif == b.dif ? a.a - a.b < b.a - b.b : a.dif < b.dif; };
int main(){
    cin.tie(0) -> sync_with_stdio(0);
    int t;
    cin >> t;
    for(int _ = 0; _ < t; _++){
        int n, x;
        cin >> n >> x;
        vector<int> v(2*n);
        for(int i = 0; i < n*2 ; i++){
            int num;
            cin >> num;
            v[i] = num;
        }
        sort(v.begin(), v.end());
        bool flag = true;
        for(int i = 0; i < n ; i++){
            if(v[i+n] - v[i] < x){
               flag = false;
               break;
            }
        }
        if(flag) cout << "YES" << endl;
        else  cout << "NO" << endl;
    } 
}