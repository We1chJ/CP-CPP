#include "bits/stdc++.h"

using namespace std;

int seg[200002];

int n;

void update(int a, int val){
    a += n;
    seg[a] += val;
    for(a /= 2; a > 0; a /= 2){
        seg[a] = seg[a*2] + seg[a*2+1];
    }
}

int query(int a, int b){
    int sum = 0;
    a += n, b += n;
    while(a <= b){
        if(a%2 == 1) sum += seg[a++];
        if(b%2 == 0) sum += seg[b--];
        a /= 2;
        b /= 2;
    }
    return sum;
}

int main(){
    freopen("bphoto.in", "r", stdin);
    freopen("bphoto.out", "w", stdout);

    cin.tie(0)->sync_with_stdio(0);
    cin >> n;
    unordered_map<int, int> m;
    vector<int> v(n+1);
    for(int i = 1; i <= n; i++){
        int a;
        cin >> a;
        v[i] = a;
        m[a] = i;
    }
    
    sort(v.begin(), v.end());
    int ans = 0;
    for(int i = 1; i <= n; i++){
        int a = v[i];
        int index = m[a];
        int l = index-1 - query(1, index-1);
        int r = n - index - query(index+1, n);   
        if(l > 2*r || r > 2*l)
            ans++;
        update(index, 1);
    }

    cout << ans << endl;
}