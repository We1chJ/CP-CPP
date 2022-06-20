#include "bits/stdc++.h"

using namespace std;


int uf[200001], height[200001];
int find(int a){
    if(uf[a] != a)
        uf[a] = find(uf[a]);

    return uf[a];
}
void unite(int a, int b){
    int rootA = find(a);
    int rootB = find(b);

    if(height[rootA] > height[rootB]){
        uf[rootB] = rootA;
        height[rootA] = max(height[rootA], height[rootB] + 1);
    } else{
        uf[rootA] = rootB;
        height[rootB] = max(height[rootB], height[rootA] + 1);
    }
}



int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, q;
    cin >> n >> q;

    for(int i = 0; i <= n; i++){
        uf[i] = i;
        height[i] = 0;
    }

    for(int i = 0 ; i < n + q; i++){
        int t, a, b;
        cin >> t >> a >> b;
        if(t == 0){
            unite(a, b);
        }else{
            cout << (int)(find(a) == find(b)) << endl;
        }
    } 
    return 0;
}