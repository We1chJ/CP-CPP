#include "bits/stdc++.h"

using namespace std;

int uf[200001];
int height[200001];

int find(int x){
    if(uf[x] != x)
        uf[x] = find(uf[x]);
    return uf[x];
}

void unite(int a, int b){
    a = find(a);
    b = find(b);
    if(height[a] < height[b])
        swap(a, b);
    uf[b] = a;
    // height[a] = max(height[a], height[b] + 1);
    height[a] += height[b];
}

int main(){
    cin.tie(0) -> sync_with_stdio(0);

    int t;
    cin >> t;
    label: while(t--){
        int n;
        cin >> n;
        int cnt[n+1];
        for(int i = 0; i <=n; i++){
            uf[i] = i;
            height[i] = 1;
            cnt[i] = 0;
        }

        for(int i = 0 ; i < n ; i++){
            int a, b;
            cin >> a >> b;
            cnt[a]++, cnt[b] ++ ;
            if(find(a) != find(b))
                unite(a, b);
        }

        for(auto a : cnt){
            if(a > 2){
                cout << "NO" << endl;
                goto label;
            }
        }
        for(int i = 1; i <= n; i++){
            int num = find(i);
            int a = height[num];

            if(height[num] % 2 != 0){
                cout << "NO" << endl;
                goto label;
            }
        }
        cout << "YES" << endl;
    }
}