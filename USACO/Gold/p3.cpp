// DSU

#include"bits/stdc++.h"
using namespace std;
using ll = long long ;
vector<int> adj[200001];
vector<int> friends(200001);

bool visited[200001];

struct cmp
{
    bool operator()(int a, int b)
    {
        return friends[a] > friends[b];
    }
};


priority_queue<int, vector<int>, cmp> pq;

void dfs(int cur){
    visited[cur] = true;
    pq.push(cur);
    for(auto a : adj[cur]){
        if(!visited[a])
            dfs(a);
    }
}


int main(){
    cin.tie(0)->sync_with_stdio(0);

    int n, m;
    cin >> n >> m;
    for(int i = 0; i < m; i++){
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
        friends[a]++;
        friends[b]++;
    }

    ll ans = 0;
    for(int i = 1; i <= n; i++){
        if(!visited[i]){
            dfs(1);
            ans = max(ans, (ll)pq.size() * friends[pq.top()]);
            while(!pq.empty()){
                int num = pq.top();
                pq.pop();
                for(auto a : adj[num]){
                    friends[a]--;
                }
                friends[num] = 0;
                ans = max(ans, (ll)pq.size() * friends[pq.top()]);
            }
        }
    }
    cout << ans << endl;   

    
}