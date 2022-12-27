#include "bits/stdc++.h"

using namespace std;
vector<int> adj[200001];


int main(){
    cin.tie(0)->sync_with_stdio(0);
    int n;
    cin >> n;
    for(int i = 0; i < n; i++){
        int a , b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    
    
}