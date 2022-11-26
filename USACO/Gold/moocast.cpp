#include "bits/stdc++.h"

using namespace std;
using ll = long long ;

int main(){
    freopen("moocast.in", "r", stdin);
    freopen("moocast.out", "w", stdout);

    cin.tie(0)->sync_with_stdio(0);

    int n ;
    cin >> n;
    vector<pair<int, int>> cow(n);
    for(int i = 0; i < n ; i++){
        int a, b;
        cin >> a >> b;
        cow[i] = {a, b};
    }
    
    ll l = 0, r = 25000*25000*2;
    while(l < r){
        ll mid = (l + r)/2;
        
        bool connected[n];
        for(int i = 0; i < n ;i ++){
            connected[i] = false;
        }
        connected[0] = true;
        queue<int> q;
        q.push(0);
        while(!q.empty()){
            int cur = q.front();
            q.pop();

            for(int i = 0; i < n; i++){
                if(!connected[i]){
                    if(abs(cow[i].first-cow[cur].first)*abs(cow[i].first-cow[cur].first) + abs(cow[i].second-cow[cur].second)*abs(cow[i].second-cow[cur].second) <= mid){
                        q.push(i);
                        connected[i] = true;
                    }
                }
            }
        }
        bool possible = true;
        for(auto i : connected){
            if(i == false)possible = false;
        }        
        if(possible)
            r = mid;
        else
            l = mid + 1;
    }
    cout << l << endl;
}