#include "bits/stdc++.h"
using namespace std;
using ll = long long;

vector<int> adj[100001];
bool visited[5], on_stack[5];
vector<int> cycle;

int n, m;

bool dfs(int node){
    visited[node] = on_stack[node] = true;
    for(auto a : adj[node]){
        if(on_stack[a]){
            cycle.push_back(node);
            on_stack[node] = on_stack[a] = false;
            return true;
        }else if(!visited[a]){
            if(dfs(a)){
                if(on_stack[node]){
                    cycle.push_back(node);
                    on_stack[node] = false;
                    return true;
                }else {
                    cycle.push_back(node);
                    return false;
                }
            }
            if(!cycle.empty())
                return false;
        }
    }
    on_stack[node] = false;
    return false;
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    cin >> n >> m;
    for(int i = 0; i < m; i++){
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
    }
    for(int i = 1; cycle.empty() & i <= n; i++){
        dfs(i);
    }

    if(cycle.empty())
        cout << "IMPOSSIBLE" << endl;
    else{
        reverse(cycle.begin(), cycle.end());
        cout << cycle.size() + 1 << endl;
        for(auto a : cycle) cout << a << " ";
        cout << cycle.at(0);
    }

}