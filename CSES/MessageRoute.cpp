#include "bits/stdc++.h"

using namespace std;


int main(){
    cin.tie(0)->sync_with_stdio(0);

    int n, m;
    cin >> n >> m;
    vector<int> adj[n+1];
    for(int i = 1; i <= m; i++){
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    vector<int> dist(n+1, INT_MAX);
    vector<int> par(n+1, -1);

    dist[1] = 0;
    queue<int> q;
    q.push(1);
    while(!q.empty()){
        int cur = q.front();
        q.pop();
        for(auto &a : adj[cur]){
            if(dist[a] == INT_MAX){
                q.push(a);
                dist[a] = dist[cur] + 1;
                par[a] = cur;
            }
        }
    }

    if(dist[n] == INT_MAX){
        cout << "IMPOSSIBLE\n";
    }else{
        vector<int> ans;
        int cur = n;
        while(par[cur] != -1){
            ans.push_back(cur);
            cur = par[cur];
        }
        ans.push_back(1);
        reverse(ans.begin(), ans.end());
        cout << ans.size() << endl;
        for(auto &a : ans){
            cout << a << " ";
        }
        cout << "\n";
    }

}