#include "bits/stdc++.h"
using namespace std;
int n, m;
vector<string> spotty(500), plain(500);
bool sim(int length){
    for(int start = 0; start <= m-length; start++){
        unordered_set<string> sofar;
        for(int i = 0; i < n; ++i){
            sofar.insert(spotty[i].substr(start, length));
        }
        for(int i = 0; i < n; i++){
            string str = plain[i].substr(start, length);
            if(sofar.count(str) != 0)
                goto here;
        }
        return true;
        here:;
    }
    return false;
}
int main(){
    freopen("cownomics.in", "r", stdin);
    freopen("cownomics.out", "w", stdout);
    cin.tie(0)->sync_with_stdio(0);
    cin >> n >> m;
    for(int i = 0; i < n; i++){
        cin >> spotty[i];
    }
    for(int i = 0; i < n; i++){
        cin >> plain[i];
    }
    int l = 1;
    int r = m;
    while(l < r){
        int mid = (l+r)/2;
        if(!sim(mid))
            l = mid + 1;
        else r = mid;
    }
    cout << r << endl;
    return 0;
}