// least common ancestor

#include "bits/stdc++.h"
using namespace std;
vector<int> adj[200001];
int cnt = 0;
int st[200001];

int seg[800004];

int n, q;

void update(int a, int newVal, int len){
    a += len;
    seg[a] = newVal;
    for(a /= 2; a >= 1; a /= 2){
        seg[a] = min(seg[a*2], seg[a*2+1]);
    }    
}

int query(int a, int b){
    a += 2*n;
    b += 2*n;
    int ans = INT_MAX;
    while(a <= b){
        if(a % 2 == 1) ans = min(ans, seg[a++]);
        if(b % 2 == 0) ans = min(ans, seg[b--]);
        a /= 2;
        b /= 2;
    }
    return ans;
}

void dfs(int node, int parent){
    st[node] = cnt;
    update(cnt++, node, 2*n);
    for(auto a : adj[node]){
        if(a != parent){
            dfs(a, node);
            update(cnt++, node, 2*n);
        }
    }
}

int main(){
    cin.tie(0) ->sync_with_stdio(0);
    cin >> n >> q;
        
    for(int i = 2; i <= n; i++){
        int a;
        cin >> a;
        adj[a].push_back(i);
        adj[i].push_back(a);
    }
    
    dfs(1, 0);
    
    for(int i =0 ; i < q; i++){
        int a, b;
        cin >> a >> b;
        if(st[a] > st[b]) swap(a, b);
        cout << query(st[a], st[b]) << endl;
    }
}