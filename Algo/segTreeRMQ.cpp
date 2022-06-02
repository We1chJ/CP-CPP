#include "bits/stdc++.h"

using namespace std;

int st[400001];
int n, q;

void update(int pos, int val){
    pos += n;
    st[pos] += val;
    for(pos /= 2; pos >= 1; pos /=2){
        st[pos] = min(st[pos*2], st[pos*2+1]);
    }
}

int query(int a, int b){
    a += n;
    b += n;
    
    int res = 1e18;
    while(a <= b){
        if(a %2 == 1) res = min(res, st[a++]);
        if(b %2 == 0) res = min(res, st[b--]);
        a /= 2;
        b /= 2;
    }

    return res;
}


int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> q;

    for(int i = 1; i <= n; i ++){
        int num;
        cin >> num;
        update(i, num);
    }

    for(int i = 0; i < q; i++){
        int t, a, b;
        cin >> t >> a >> b;
        if(t == 1){
            update(a, b - st[a + n]); 
        }else 
            cout << query(a, b) << endl;
    
    }


    return 0;
}