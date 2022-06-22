// Bellman-Ford Algorithmn
// Used to calculate the shortest path from one node to every other nodes 
// Update dis of every other nodes through edges that shortens the dis until everything is finalized

// O(MN)

#include "bits/stdc++.h"

using namespace std;

long long dis[100001];

struct Edge{
    long long a,b,c;
};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n, m;
    cin >> n >> m;
    vector<Edge> edges;
    for(int i = 0; i < m; i ++){
        long long a, b, c;
        cin >> a >> b >> c;

        edges.push_back({a, b, c});
    }

    for(int i = 1; i <= n; i++){
        dis[i] = 1e14;
    }
    dis[1] = 0;

    // n-1 loops will be enough to update all nodes because it would take at most n-1 edges to reach any nodes
    for(int i = 1; i <= n-1 ; i++){
        bool flag = false;
        for(auto e : edges){
            long long a, b, c;
            a = e.a;
            b = e.b;
            c = e.c;
            if(dis[a] + c < dis[b]) flag = true;
            dis[b] = min(dis[b], dis[a] + c);
        }
        // if no edges are used to update the dis, end the loop early
        if(!flag) break;
    }

    // if there are negative cycles inside, do another loop to see if any node's dis is updated, if so there must be a negative cycle
    // this can find all negative cycles in the whole graph
    // just record all the edges that changes the dis of the nodes

    for(int i =1; i <= n; i++) {
        cout << dis[i] << " ";
    }
}