#include "bits/stdc++.h"
using namespace std;
using ll = long long;

vector<int> adj[200001];

ll pfixA[200001], pfixB[200001];
pair<int, int> val[200001];

int ans[200001];
vector<ll> vb;

void dfs(int par, int cur, ll sumA, ll sumB){
    sumA += val[cur].first;
    sumB += val[cur].second;
    pfixA[cur] = sumA;
    pfixB[cur] = sumB;

    vb.push_back(sumB);
    ans[cur] = upper_bound(vb.begin(), vb.end(), sumA) - vb.begin();

    for(auto a : adj[cur]){
        if(a != par)
            dfs(cur, a, sumA, sumB);
    }
    vb.pop_back();
}

int main(){
    cin.tie(0) -> sync_with_stdio(0);
    int t;
    cin >> t;
    while(t--){
        int n ;
        cin >> n;
        for(int i = 0 ; i <= n; i++){
            adj[i].clear();
            val[i] = {0, 0};
            pfixA[i] = pfixB[i] = 0;
            
        }

        for(int i = 2; i <= n; i++){
            int num;
            cin >> num;
            adj[num].push_back(i);
            int a, b;
            cin >> a >> b;
            val[i] = {a, b};
        }
        val[1] = {0, 0};
        dfs(0, 1, 0, 0);

        for(int i = 2; i <= n; i++)
            cout << ans[i] - 1 << " ";
        cout << endl;
    }
}