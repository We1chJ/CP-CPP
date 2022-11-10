#include "bits/stdc++.h"

using namespace std;
using ll = long long;
ll arr[200001];
int main(){

    cin.tie(0)->sync_with_stdio(0);
    int n, q;
    cin >> n >> q;
    for(int i = 0; i <n ;i ++){
        int a ;
        cin >> a;
        arr[i+1] = arr[i] + a;
    }
    for(int i = 0; i < q; i++){
        int a, b;
        cin >> a >> b;
        ll dif = (arr[b] - arr[a-1]);
        cout << dif << endl;
    }
}