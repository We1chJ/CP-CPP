// Baltic OI 2010-PCB

#include "bits/stdc++.h"

using namespace std;

int lis = 0;
pair<int, int> a[100000];
set<int> s;


int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    for(int i = 0; i < n; i++){
        cin >> a[i].first >> a[i].second;
    }

    sort(a, a+n, greater<pair<int, int>>());

    for(int i = 0; i < n; i++){
        if(s.upper_bound(a[i].second) == s.end()) lis++;
        else s.erase(s.upper_bound(a[i].second));
        s.insert(a[i].second);
    }

    cout << lis;
    return 0;
}