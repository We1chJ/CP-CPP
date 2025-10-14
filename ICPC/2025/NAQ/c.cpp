#include "bits/stdc++.h"

using namespace std;

int main(){

    cin.tie()->sync_with_stdio(0);

    int n, k;
    cin >> n >> k;
    unordered_set<int>s;
    for(int i = 0; i < n; i++){
        int a;
        cin >> a;
        s.insert(a);
    }
    
    cout << min(k, (int)s.size()) << endl;

}