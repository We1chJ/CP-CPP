#include "bits/stdc++.h"
using namespace std;
vector<int> adj[100001];
vector<int> dis(100001, INT_MAX);
int parent[100001];
int main(){
    cin.tie(0)->sync_with_stdio(0);

    int n, m;
    cin >> n >> m;
    for(int i =0 ; i < m; i++){
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    queue<int> q;
    q.push(1);
    dis[1] = 0;

    while(!q.empty()){
        int cur = q.front();
        q.pop();
        for(auto a : adj[cur]){
            if(dis[a] == INT_MAX){
                dis[a] = dis[cur] + 1;
                parent[a] = cur;
                q.push(a);
            }
        }
    }

    if(dis[n] == INT_MAX)
        cout << "IMPOSSIBLE" << endl;
    else{
        cout << dis[n]+1 << endl;
        vector<int> v;
        int cnt = dis[n];
        v.push_back(n);
        int cur = n;
        while(cnt != 0){
            for(auto a : adj[cur]){
                if(dis[a] == cnt -1){
                    cur = a;
                    break;
                }
            }
            v.push_back(cur);
            cnt--;
        }
        reverse(v.begin(), v.end());
        for(auto a: v)
            cout << a << " " ;
        cout << endl;
    }
    
}