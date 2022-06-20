#include "bits/stdc++.h"

using namespace std;

vector<int> adj[100001], topSort;
bool visited[100001];

int n, m;

//Recursive DFS

// void dfs(int node){
//     for(auto &a : adj[node]){
//         if(!visited[a]){
//             visited[a] = true;
//             dfs(a);
//         } 
//     }

//     topSort.push_back(node);
// }

// void solve(){
//     for(int i = 1; i <= n;i ++){
//         if(!visited[i]){
//             visited[i] = true;
//             dfs(i);
//         } 
//     }

//     reverse(topSort.begin(), topSort.end());
// }


// Iterative DFS

// void solve(){
//     stack<int> cnt[n+1];
//     for(int i = 1; i <= n; i++){
//         for(auto &a : adj[i]){
//             cnt[i].push(a);
//         }
//     }

//     for(int i = 1; i <= n;i ++){
//         if(!visited[i]){
//             visited[i] = true;
//             stack<int> s;
//             s.push(i);
//             while(!s.empty()){
//                 int node = s.top();

//                 while(!cnt[node].empty() && visited[cnt[node].top()]) cnt[node].pop();

//                 if(cnt[node].empty()){
//                     s.pop();
//                     topSort.push_back(node);
//                     continue;
//                 }

//                 int next = cnt[node].top();
//                 if(!visited[next]){
//                     visited[next] = true;
//                     s.push(next);
//                     cnt[node].pop();
//                 }
//             }
//         }
//     }
//     reverse(topSort.begin(), topSort.end());
// }


void solve(){
    queue<int> q;
    int in[n+1] = {};

    for(int i = 1; i <= n; i++){
        for(auto &a : adj[i]){
            in[a] ++;
        }
    }
    
    for(int i = 1; i <= n ;i++){
        if(in[i] == 0) q.push(i);
    }

    while(!q.empty()){
        int node = q.front();
        q.pop();

        for(auto &a : adj[node]){
            in[a]--;
            if(in[a] == 0) q.push(a);
        }
        topSort.push_back(node);
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;
    for(int i = 0; i < m; i ++){
        int a,b;
        cin >> a >> b;
        adj[a].push_back(b);
    }

    solve();

    if(topSort.size() != n) {
        cout << "IMPOSSIBLE" << endl;
        return 0;
    }
    
    int ind[n+1];

    for(int i = 1; i <= n; i++){
        ind[topSort[i-1]] = i-1;
    }

    for(int i = 1; i <= n; i++){
        for(auto &a : adj[i]){
            if(ind[a] < ind[i]){ 
                cout << "IMPOSSIBLE" << endl;
                return 0;
            }
        }
    }

    for(auto &a : topSort)
        cout << a << " ";    

}