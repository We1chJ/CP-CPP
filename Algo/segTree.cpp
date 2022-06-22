// O(logN) operations
// larger constant factors

#include "bits/stdc++.h"

using namespace std;

long long st[400001];
int n, q;

void update(int pos, int val){
    pos += n;
    st[pos] += val;
    for(pos /= 2; pos >= 1; pos /=2){
        st[pos] = st[pos*2] + st[pos*2+1];
    }
}

long long query(int a, int b){
    a += n;
    b += n;
    
    long long sum = 0;
    while(a <= b){
        if(a %2 == 1) sum += st[a++];
        if(b %2 == 0) sum += st[b--];
        a /= 2;
        b /= 2;
    }

    return sum;
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