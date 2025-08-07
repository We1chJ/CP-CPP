#include "bits/stdc++.h"
using namespace std;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int t;
    cin >> t;
    while(t--){
        int n; cin >> n;
        int px, py, qx, qy;
        cin >> px >> py >> qx >> qy;
        long long sum = 0;
        vector<int> v (n);
        int mx = 0;
        for(int i = 0 ; i < n; i++){
            int a ;
            cin >> a;
            sum += a;
            v[i] = a;
            mx = max(mx, a);
        }
        long long dx = qx - px;
        long long dy = qy - py;
        long long dis = dx * dx + dy * dy;

        int cur = (mx >= sum-mx) ? mx*2-sum : 0;
        if(dis <= sum * sum && dis >= cur * cur){
            cout << "yes" << endl;
        }else{
            cout << "no" << endl;
        }
    }
}