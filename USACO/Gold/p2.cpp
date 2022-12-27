#include"bits/stdc++.h"
using namespace std;
using ll = long long;
using pi = pair<int, int>;

int mount[2001];

bool work(pi a, pi b, pi mid){
    pi v1 = {b.first - a.first, b.second - a.second};
    pi v2 = {mid.first - a.first, mid.second - a.second};

    int det = v1.first*v2.second - v1.second*v2.first;
    if(det > 0) return false;
    else return true;
}


// int main(){
//     int a, b, c, d, e, f;
//     cin >> a>> b >> c >> d >> e >> f;
//     cout << work({a, b}, {c, d}, {e, f});
// }

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int n ;
    cin >> n;
    for(int i = 0 ;i  <n  ;i ++){
        cin >> mount[i];
    }

    set<pair<int, int>> p;

    for(int i = 0; i < n ;i ++){
        pair<int, int> high = {i, mount[i]};
        for(int j = i+1; j<n;j++){
            if(work({i, mount[i]}, {j, mount[j]}, high))
                p.insert({i, j});
            if(mount[j] >= high.second || high.first == i) high = {j, mount[j]};
        }
    }
    
    int q;
    cin >> q;
    for(int i = 0 ; i <q ; i++){
        int a , b;
        cin >>a >> b;
        a--;
        mount[a] += b;

        // check if any pairs should be taken out
        // potential TLE, O(N^2)
        vector<pi> check;
        for(auto v : p){
            int st = v.first;
            int en = v.second;
            if(st > a || en < a) continue;
            if(!work({st, mount[st]}, {en, mount[en]}, {a, mount[a]}))
                check.push_back(v);
        }        
        for(auto v : check)
            p.erase({v.first, v.second});

        // add new pairs
        pair<int, int> high = {a, mount[a]};
        for(int i = a-1; i >= 0; i--){
            if(work({i, mount[i]}, {a, mount[a]}, high) && p.count({i, a}) == 0)
                p.insert({i, a});
            if(mount[i] >= high.second || high.first == a) high = {i, mount[i]};
        }
         high = {a, mount[a]};
        for(int i = a+1; i < n ; i++){
            if(work({a, mount[a]}, {i, mount[i]}, high) && p.count({a, i}) == 0)
                p.insert({a, i});
            if(mount[i] >= high.second || high.first == a) high = {i, mount[i]};
        }
        cout << p.size() << endl;
    }
    
}