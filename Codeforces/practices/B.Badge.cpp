#include "bits/stdc++.h"

using namespace std;

int dfs(int cur, vector<int> &suc, set<int> &visited){
    if(visited.count(cur)){
        return cur;
    }

    visited.insert(cur);
    
    return dfs(suc[cur], suc, visited);
}

int main(){
    cin.tie(0)->sync_with_stdio(0);

    int n;
    cin >> n;
    vector<int> suc(n+1);

    for(int i = 1; i <= n; i++){
        cin >> suc[i];
    }
    set<int> visited;
    for(int i = 1; i <=n ;i++){
        visited.clear();
        cout << dfs(i, suc, visited) << " ";
    }

}