#include "bits/stdc++.h"

using namespace std;

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    int arr[n];
    for(int i = 0; i < n ; i++){
        cin >> arr[i];
    }
    set<int> s;
    int ans = 0;
    int r = -1;
    for(int i = 0; i < n ; i++){
        while(r < n-1 && s.count(arr[r+1])< 1) s.insert(arr[++r]);
        ans = max(ans, r - i + 1);
        s.erase(arr[i]);
    }

    cout << ans << endl;
}