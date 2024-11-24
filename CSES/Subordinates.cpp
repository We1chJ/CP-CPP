// #include "bits/stdc++.h"

// using namespace std;

// vector<int> arr(200005);
// vector<int> adj[200005];

// void dfs(int cur, int par){
//     for(int & a: adj[cur]){
//         if(a != par)
//             dfs(a, cur);
//     }

//     arr[par] += (arr[cur] + 1);
// }


// int main(){
//     cin.tie(0)->sync_with_stdio(0);

//     int n ;
//     cin >> n;

//     for(int i = 2; i <= n ;i ++){
//         int a;
//         cin >> a;
//         // adj[i].push_back(a);
//         adj[a].push_back(i);
//     }

//     dfs(1, 0);
//     for(int i = 1; i <= n; i++){
//         cout << arr[i];
//         if(i != n) cout << " ";
//     }
//     cout << "\n";
// }

// Attemp on 11/23/2024

#include "bits/stdc++.h"

using namespace std;

vector<int> adj[200005];
vector<int> cnt(200005);

void dfs(int p, int cur){
    for(auto &a : adj[cur]){
        if(a != p){
            dfs(cur, a);
        }
    }
    cnt[p] += cnt[cur] + 1;
}

int main(){
    cin.tie(0)->sync_with_stdio(0);

    int n =0 ;
    cin >> n;
    for(int i = 2 ; i <= n; i++){
        int a;
        cin >> a;
        adj[a].push_back(i);
        adj[i].push_back(a);
    }

    dfs(0, 1);
    for(int i = 1; i <=n ;i ++){
        cout << cnt[i] << " ";
    }
    cout << endl;

}