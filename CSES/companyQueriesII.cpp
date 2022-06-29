// Least Common Ancestors with Range Minimum Queries by using Segment Tree

#include "bits/stdc++.h"

using namespace std;


// IMPORTANT: the index of the node is always growing larger than those above it
// Look at problem statment


// const int k = 19;
// int sparse[400002][k+1];
// vector<int> adj[200001];
// int timer = 1;
// int first[200001]; 

// void dfs(int parent, int node){
//     first[node] = timer;
//     sparse[timer++][0] = node;
//     for(int i : adj[node]){
//         if(i != parent){
//             dfs(node, i);
//             sparse[timer++][0] = node;
//         }
//     }
// }

// int main(){
//     ios_base::sync_with_stdio(0);
//     cin.tie(0);

//     int n, q;
//     cin >> n >> q;
//     for(int i = 2; i <= n; i++){
//         int a ;
//         cin >> a;
//         adj[i].push_back(a);
//         adj[a].push_back(i);
//     }
//     dfs(0, 1);

//     for(int i = 1; i <= k; i++){
//         for(int j = 1; j + (1 << i) <= n*2; j++){ // remember the size of the whole sparse table is 2N now
//             sparse[j][i] = min(sparse[j][i-1], sparse[j + (1 << (i-1))][i-1]);
//         }
//     }    

//     int log[400002];

//     log[1] = 0;
//     for(int i = 2; i < 400002; i++){
//         log[i] = log[i/2]+1;
//     }   

//     vector<int> ans;

//     for(int i = 0; i < q; i++){
//         int a, b;
//         cin >> a >> b;

//         a = first[a];
//         b = first[b];
//         if(a > b) swap(a, b);
//         ans.push_back(min(sparse[a][log[b - a+1]], sparse[b - (1 << log[b - a + 1]) + 1][log[b- a + 1]]));
//     }    
//     for(auto a : ans)
//         cout << a << endl;
// }

// O(6N)
// using seg tree
vector<int> adj[200001];
int timer = 1;
int first[200001]; 
int seg[800004];


void update(int pos, int val, int n){
    pos += n;
    seg[pos] = val;
    for(pos/=2; pos >= 1; pos/= 2){
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

void dfs(int parent, int node, int n){
    first[node] = timer;
    update(timer++, node, n);
    for(int i : adj[node]){
        if(i != parent){
            dfs(node, i, n);
            update(timer++, node, n);
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, q;
    cin >> n >> q;
    for(int i = 2; i <= n; i++){
        int a ;
        cin >> a;
        adj[i].push_back(a);
        adj[a].push_back(i);
    }

    dfs(0, 1, 2*n);
    for(int i = 0; i < q; i++){
        int a, b;
        cin >> a >> b;

        a = first[a];
        b = first[b];
        if(a > b) swap(a, b);
        cout << query(a, b, 2*n) << endl;
    }    
}