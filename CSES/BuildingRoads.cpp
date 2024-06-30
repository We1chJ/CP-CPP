#include "bits/stdc++.h"

using namespace std;
bool visited[100005];
vector<int> adj[100005];

void dfs(int cur){
    if(visited[cur])
        return;
    visited[cur] = true;
    for(auto & a: adj[cur]){
        dfs(a);
    }
}


int main() {
    cin.tie(0)->sync_with_stdio(0);

    int n, m;
    cin >> n >> m;
    
    for(int i= 0; i < m; i++){
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    int cnt = 0;
    vector<int> ans;
    for(int i = 1; i <= n; i++){
        if(!visited[i]){
            cnt++;
            ans.push_back(i);
            dfs(i);
        }
    }

    cout << cnt - 1 << endl;
    for(int i = 0 ; i < ans.size()-1; i++){
        cout << ans[i] << " " << ans[i+1] << endl;
    }


    
    
}