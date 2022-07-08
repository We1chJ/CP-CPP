// Used to find Minimum/Maximum Spanning Tree
// O(ElogE) - using Union Find Structure

#include "bits/stdc++.h"

using namespace std;
using ll = long long;

int uf[100001];
int height[100001];

int find(int a){
    if(a != uf[a])
        uf[a] = find(uf[a]);
    return uf[a];
}

void unite(int a, int b){
    int pa = find(a);
    int pb = find(b);

    if(height[pa] < height[pb]) {
        swap(a, b);
        swap(pa, pb);
    }

    uf[pb] = pa;
    height[a] = max(height[pa], height[pb] + 1);
}

auto cmp = [](const tuple<int, int, int> &a, const tuple<int, int, int> &b) {return get<2>(a) < get<2>(b);};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    for(int i =1; i<= n; i++){
        uf[i] = i;
        height[i] = 0;
    }
    
    vector<tuple<int, int, int>> edge;
    ll ans = 0;

    for(int i = 0; i < m; i++){
        int a, b, c;

        cin >> a >> b>>c ;
        edge.push_back({a, b, c});
    }
    sort(edge.begin(), edge.end(), cmp);

    int cnt = 0;

    for(auto a : edge){
        int from, to, w;
        tie(from, to, w) = a;
        if(find(from) != find(to)) {
            unite(from, to);
            ans += w;
            cnt++;
        }
    }
    
    

    if(cnt != n-1)
        cout << "IMPOSSIBLE" << endl;
    else
        cout << ans << endl;
}