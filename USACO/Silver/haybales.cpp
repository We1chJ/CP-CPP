#include "bits/stdc++.h"

using namespace std;

int main(){
    freopen("haybales.in","r",stdin);
	freopen("haybales.out","w",stdout);
    cin.tie(0) ->sync_with_stdio(0);
    int n, q;
    cin >> n >> q;
    vector<int> v(n);
    for(int i = 0; i < n ; i++){
        cin >> v[i];
    }
    sort(v.begin(), v.end());
    for(int i = 0; i < q; i++){
        int a, b ;
        cin >> a >> b;
        cout << upper_bound(v.begin(), v.end(), b) - lower_bound(v.begin(), v.end(), a) << endl;
    }
}