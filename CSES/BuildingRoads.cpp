#include "bits/stdc++.h"

using namespace std;

vector<int> adj[100001];
bool visited[100001]; // set default values 0 (false)

void dfs(int cur){
    if(visited[cur]) return;
    visited[cur] = true;
    
    for(auto next : adj[cur]){
        dfs(next);
    }   
}

int main(){
    int n, m;
    cin >> n >> m;

    for(int i  = 0; i < m; i++){
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    // count number of components
    int cnt = 0;

    vector<int> nodes;

    // try every single node
    for(int i = 1; i<=n;i++){
        // only start a traversal on the node if its not visited yet
        if(!visited[i]){
            nodes.push_back(i);
            // traverse over the whole components
            dfs(i);
            cnt ++;
        }
    }

    cout << cnt -1  << endl;

    for(int i = 1; i< nodes.size(); i++){
        cout << nodes[0] << " " << nodes[i] << endl;
    }

}