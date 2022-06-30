#include "bits/stdc++.h"

using namespace std;

vector<int> adj[200001];

int fir[200001], sec[200001], ans[200001];
void dfs1(int node, int parent){

    for(auto a : adj[node]){
        if(a != parent){
            dfs1(a, node);
            if (fir[a] + 1 > fir[node]) {
                sec[node] = fir[node];
                fir[node] = fir[a] + 1;
            } else if (fir[a] + 1 > sec[node]) {
                sec[node] = fir[a] + 1;
            }
        }
    }
}

void dfs2(int node, int parent, int p){
    ans[node] = max(p, fir[node]);
    for(auto a : adj[node]) {
        if(a != parent){
            if(fir[a] + 1 == fir[node]) dfs2(a, node, max(p+1, sec[node] + 1));
            else dfs2(a, node, ans[node]+1);
        }
    }
}

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n ;
    cin >> n;
    for(int i = 0; i < n-1; i++){
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    dfs1(1, 0);
    dfs2(1, 0, 0);

    for (int i = 1; i <= n; i++) cout << ans[i] << ' ';
	return 0;

}