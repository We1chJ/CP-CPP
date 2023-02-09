#include "bits/stdc++.h"

using namespace std;

int main(){
    freopen("art2.in", "r", stdin); 
    freopen("art2.out", "w", stdout);
    cin.tie(0)->sync_with_stdio(0);
    int n;
    cin >> n;
    vector<int> seq (n+2);
    vector<pair<int, int>> pt(n+2, {-1, -1});
    seq[0] = seq[n+1] = 0;
    for(int i = 1; i <= n; i++){
        int a ;
        cin >>a ;
        seq[i] = a;
        if(pt[a].first == -1){
            pt[a] = {i, i};
        }else{
            pt[a].second = i;
        }
    }
    pt[0] = {0, n+1};

    stack<int> s;
    int ans = 0;
    for(int i = 0; i <= n+1; i ++ ){
        int a = seq[i];
        
        if(pt[a].first == i){
            s.push(a);   
            ans = max(ans, (int) s.size());
        }
        if(s.top() != a){
            cout << -1 << endl;
            return 0;
        }
        
        if(pt[a].second == i){
            s.pop();
            pt[a] = {-1, -1};
        }
        
    }
    cout << ans - 1<< endl;
}