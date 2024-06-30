#include "bits/stdc++.h"
using namespace std;

vector<int> adj[100005];
int arr[100005];
bool fail;
void dfs(int cur, int color){
    if(arr[cur] != 0){
        if(arr[cur] != color){
            fail = true;
        }            
        return ;
    }

    arr[cur] = color;
    for(auto & a : adj[cur]){
        dfs(a, (color == 1) ? 2 : 1);
    }
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int n, m;
    cin >> n >> m;
    for(int i  =0 ; i < m; i++){
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    for(int i  =1; i <= n; i++){
        if(arr[i] == 0){
            dfs(i, 1);
        }
    }

    if(fail) cout << "IMPOSSIBLE" << endl;
    else{
        for(int i  = 1; i <= n; i++){
            cout << arr[i] << " " ;
        }
        cout << "\n";
    }

}