#include "bits/stdc++.h"
using namespace std;

using ll = long long;

vector<pair<int, int>> adj[100001];
bool visited[100001];

int main(){

    cin.tie(0)->sync_with_stdio(0);
    int n, m;
    cin >> n >> m;
    for(int i = 1; i <= m; i++){
        int a, b, c;
        cin >> a >> b>> c;
        adj[a].push_back({b, c});
        adj[b].push_back({a, c});
    }

    using T = tuple <int, int ,int>;
    priority_queue<T, vector<T>, greater<T>> pq;

    visited[1] = true;

    for(auto e : adj[1]){
        pq.push({e.second, 1, e.first});
    }
    ll ans = 0;
    int cnt = 0;
    while(!pq.empty()){
        int a, b, c;
        tie(c, a, b) = pq.top();
        pq.pop();
        if(visited[b]) continue;
        visited[b] = true;
        ans += c;
        cnt ++ ;
        for(auto e : adj[b]){
            pq.push({e.second, b, e.first});
        }
    }
    if(cnt != n-1) cout << "IMPOSSIBLE" <<endl;
    else cout << ans << endl;
}