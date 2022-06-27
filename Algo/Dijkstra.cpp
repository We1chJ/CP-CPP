// Dijkstra to find min dis from source node to all other nodes
// O(MlogN)

#include "bits/stdc++.h"

using namespace std;

using ll = long long;

ll dis[100001];
bool visited[100001];
vector<pair<int, int>> adj[100001];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    for(int i = 0; i < m; i++){
        int a, b, c;
        cin >> a >> b>> c;
        adj[a].push_back(make_pair(b,c));
    }

    for(int i = 1; i <= n; i++){
        dis[i] = 1e18;
    }
    
    using T = pair<ll, int>;
    priority_queue<T, vector<T>, greater<T>> pq;
    pq.push(make_pair(0, 1));
    dis[1] = 0;

    while(!pq.empty()){
        ll dist; int node;
        tie(dist, node) = pq.top();
        pq.pop();
        
        if(visited[node]) continue;

        visited[node] = true;

        for(pair<int, int> a : adj[node]){
            int to, weight;
            tie(to, weight) = a;
            
            if(dis[to] > dist + weight){
                dis[to] = dist + weight;
                pq.push({dis[to], to});
            }
        }
    }

    for(int i = 1; i<=n; i++){
        cout << dis[i] << " ";
    }
    
}