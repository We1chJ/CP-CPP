// range query and update on subtrees
// the st and en arrays also represent the tree traverse index of the nodes (smart)

#include "bits/stdc++.h"

using namespace std;

vector<int> adj[200001];
int val[200001];

long long seg[400002];

int st[200001], en[200001];

int timer = 0;

void dfs(int parent, int pos){
    st[pos] = timer++;
    for(auto a : adj[pos]){
        if(a != parent){
            dfs(pos, a);
        }
    }
    en[pos] = timer-1;
}

void update(int node, int val, int &n){
    node += n;
    seg[node] = val;

    for(int p = node/2; p >= 1; p /=2){
        seg[p] = seg[p*2] + seg[p*2+1];
    }
}

long long query(int l, int r, int &n){
    l += n;
    r += n;
    long long sum = 0;
    while(l <= r){
        if(l%2 == 1) sum += seg[l++];
        if(r%2 == 0) sum += seg[r--];
        l /=2;
        r /=2;
    }
    return sum;
}

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n , q;
    cin >> n >> q;
    for(int i = 0; i < n; i++){
        int a ;
        cin >> a;
        val[i+1] = a;
    }
    for(int i =0 ; i < n-1; i++){
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    
    dfs(0, 1);

    for(int i= 1; i <= n; i++){
        update(st[i], val[i], n);
    }

    for(int i = 0; i < q; i++){
        int t;
        cin >> t;
        if(t == 1){
            int a , b;
            cin >> a >> b;
            update(st[a], b, n);
        }else{
            int a;
            cin >> a;
            cout << query(st[a], en[a], n) << endl;
        }
    }



}