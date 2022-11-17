// topological sort
// A directed acyclic graph (DAG), not cycles
// An ordering that all nodes u -> v, u comes before v

#include "bits/stdc++.h"
using namespace std;

using ll = long long;

vector<int> adj[100001], topSort;
bool visited[100001];
int n, m;

// Recursive DFS
// void dfs(int node){
//     visited[node] = true;
//     for(auto a : adj[node]){
//         if(!visited[a])
//             dfs(a);
//     }
//     topSort.push_back(node);
// }

// void recurDFSsolve(){
//     for(int i = 1; i <= n; i++){
//         if(!visited[i]){
//             dfs(i);
//         }
//     }
//     reverse(topSort.begin(), topSort.end());
// }

// =======================================
// BFS

void solveBFS(){
    queue<int> q;
    int in[n+1] = {};

    for(int i = 1; i <= n; i++){
        for(auto a : adj[i])
            in[a] ++;
    }

    for(int i = 1; i <= n; i++){
        if(in[i] == 0)
            q.push(i);
    }
    while(!q.empty()){
        int node = q.front();
        q.pop();

        for(auto a : adj[node]){
            in[a] --;
            if(in[a] == 0) q.push(a);
        }
        topSort.push_back(node);
    }
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    cin >> n >> m;

    for(int i = 0; i< m; i++){
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
    }
    
    solveBFS();

    if(topSort.size() != n){
        cout << "IMPOSSIBLE" << endl;
        return 0;
    }

    int ind[n+1];

    for(int i = 1; i <= n; i++){
        ind[topSort[i-1]] = i-1;
    }

    for(int i = 1; i <= n; i++){
        for(auto a : adj[i]){
            if(ind[a] < ind[i]){
                cout << "IMPOSSIBLE" << endl;
                return 0;
            }
        }
    }

    for(auto a : topSort)
        cout << a << " ";   
}