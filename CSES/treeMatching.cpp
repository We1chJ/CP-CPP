#include "bits/stdc++.h"

using namespace std;

vector<int> adj[200001];

// DP on Tree Method
// int dp1[200001], dp2[200001];

// void dfs(int node, int parent){
    
//     for(auto a : adj[node]){
//         if(a != parent){
//             dfs(a, node);
//             dp2[node] += max(dp2[a], dp1[a]);
//         }
//     }
//     for(auto a : adj[node]){
//         if(a != parent){
//             dp1[node] = max(dp1[node], dp2[a] + 1 + dp2[node] - max(dp2[a], dp1[a]));
//         }
//     }
// }

// int main(){

//     ios_base::sync_with_stdio(0);
//     cin.tie(0);
//     int n;
//     cin >> n;
//     for(int i = 0; i < n-1 ; i++){
//         int a, b;
//         cin >> a >>b ;
//         adj[a].push_back(b);
//         adj[b].push_back(a);
//     }
//     dfs(1, 0);
//     cout << max(dp1[1], dp2[1]) << endl;
// }

// Greedy

int ans = 0;
bool done[200001];
void dfs(int node, int parent){
    for(auto a : adj[node]){
        if(a != parent){
            dfs(a, node);
            if(!done[a] && !done[node]){
                done[a] = done[node] = 1;
                ans++;
            }
        }
    }
}

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    for(int i = 0; i < n-1 ; i++){
        int a, b;
        cin >> a >>b ;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    dfs(1, 0);
    cout << ans << endl;
}