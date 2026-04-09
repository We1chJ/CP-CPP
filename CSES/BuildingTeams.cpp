#include "bits/stdc++.h"
using namespace std;

vector<int> adj[100001];
bool visited[100001];
int colors[100001]; // defaulted to 0
bool isPossible = true;

void dfs(int cur, int color){
    if(visited[cur]) return;
    visited[cur] = true;
    colors[cur] = color;
    for(auto a : adj[cur]){
        // report impossible if neighboring nodes share same color
        if(colors[a] == colors[cur]) {
            isPossible = false;
            return ;
        }
        dfs(a, 3 - color);
    }
}

int main(){
    int n, m;
    cin >> n >>m;

    for(int i = 0; i < m; i++){
        int a, b;
        cin >> a>> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    for(int i = 1; i<= n;i++){
        if(!visited[i]){
            dfs(i, 1);
        }
    }

    if(!isPossible){
        cout << "IMPOSSIBLE" << endl;
    }else{
        for(int i = 1; i <= n;i ++){
            cout << colors[i] << " ";
        }
        cout << endl;
    }
}