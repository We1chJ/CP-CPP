// Euler Tour -- flatten a tree into an array to perform range queries and updates on substress of a node

#include "bits/stdc++.h"
using namespace std;
using ll = long long;
vector<int> adj[200001];
int cnt = 0;
int st[200001], en[200001];

ll seg[400001];
int v[200001];

int n, q;

void update(int a, int newVal){
    a += n;
    seg[a] = newVal;
    for(a /= 2; a >= 1; a /= 2){
        seg[a] = seg[a*2] + seg[a*2+1];
    }    
}

ll query(int a, int b){
    a += n;
    b += n;
    ll sum = 0;
    while(a <= b){
        if(a % 2 == 1) sum += seg[a++];
        if(b % 2 == 0) sum += seg[b--];
        a /= 2;
        b /= 2;
    }
    return sum;
}

void dfs(int node, int parent){
    st[node] = cnt++;
    for(auto a : adj[node]){
        if(a != parent)
            dfs(a, node);
    }
    en[node] = cnt-1;
}

int main(){
    cin.tie(0) ->sync_with_stdio(0);
    cin >> n >> q;
    for(int i = 1; i <= n; i++){
        cin >> v[i];
    }
        
    for(int i = 0; i < n-1; i++){
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    
    dfs(1, 0);

    for(int i = 1; i <= n;i++){
        update(st[i], v[i]);
    }
    
    for(int i =0 ; i < q; i++){
        int t;
        cin >> t;
        if(t == 1){
            int a , b;
            cin >> a >> b;
            update(st[a], b);
        }else{
            int a ;
            cin >> a ;
            cout << query(st[a], en[a]) << endl;
        }
    }
    

}