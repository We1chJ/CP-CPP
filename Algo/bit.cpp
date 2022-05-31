// binary indexed tree
// or fenwick tree


#include "bits/stdc++.h"

using namespace std;

long long bit[200001], x[200001];

int n;
void update(int pos, long long val){
    while(pos <= n){
        bit[pos] += val;
        pos += pos & -pos;
    }
}

long long query(int a){
    long long sum = 0;
    while(a > 0){
        sum += bit[a];
        a -= a & -a;
    }
    return sum;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int q;
    cin >> n >> q;
    for(int i = 1; i <= n ; i++){
        cin >> x[i];
        update(i, x[i]);
    }
    for(int i = 0; i < q; i++){
        int type, a, b;
        cin >> type >> a >>b;
        if(type == 1){
            int diff = b - x[a];
            x[a] = b;
            update(a, diff);
        }else 
            cout << query(b) - query(a-1) << endl;
    }

    return 0;
}