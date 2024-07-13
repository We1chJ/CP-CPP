#include "bits/stdc++.h"


using namespace std;

vector<int> par (100004);
vector<int> sizes(100004);

int find(int a){
    if(a != par[a])
        par[a] = find(par[a]);
    return par[a];
}

bool join(int a, int b){
    int fa = find(a);
    int fb = find(b);
    if(fa == fb) return false;
    par[fa] = fb;
    sizes[fb] += sizes[fa];
    return true;
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int n, m;
    cin >> n >> m;
    for(int i = 1; i <= n; i++){
        par[i] = i;
        sizes[i] = 1;
    }

    int cnt = n;
    int ans = 0;
    for(int i = 0; i < m; i++){
        int a, b;
        cin >> a >> b;
        if(join(a, b)){
            cnt--;
            ans = max(ans, sizes[find(a)]);
        }

        cout << cnt << " " << ans << endl;
        
    }
}