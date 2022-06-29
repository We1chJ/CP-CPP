#include "bits/stdc++.h"

using namespace std;

vector<int> adj[200001];
int timer = 1;
int first[200001];
int seg[800004];
int depth[200001];


void update(int pos, int val, int n){
    pos += n;
    seg[pos] = val;
    for(pos/=2; pos >= 1; pos /=2){
        seg[pos] = min(seg[pos*2], seg[pos*2+1]);
    }
}


int query(int a, int b, int n){
    a += n;
    b += n;
    int ans = INT32_MAX;
    while(a <= b){
        if(a%2 == 1) ans = min(ans, seg[a++]);
        if(b%2 == 0) ans = min(ans, seg[b--]);
        a /=2;
        b /=2;
    }
    return ans;
}

void dfs(int node, int parent, int n){
    depth[node] = depth[parent] + 1;
    update(timer, depth[node], n);
    first[node] = timer++;
    for(auto a : adj[node]){
        if(a != parent){
            dfs(a, node, n);
            update(timer++, depth[node], n);
        }
    }
}

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int q, n;
    cin >> n >> q;
    for(int i = 0; i < n-1; i++){
        int a ,b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }   

    dfs(1, 0, 2*n); 

    for(int i = 0; i < q; i++){
        int a ,b;
        cin >> a >> b;
        int lca = query(min(first[a], first[b]), max(first[a], first[b]), 2*n);
        cout << depth[a] + depth[b] - 2*lca << endl;        
    }

}