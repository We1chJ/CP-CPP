#include "bits/stdc++.h"

using namespace std;

int main(){

    cin.tie()->sync_with_stdio(0);

    int n;
    cin >> n;
    vector<int> d ( n);
    for(int i = 0; i < n; i++){
        cin >> d[i];
    }
    int a1, a2, a3;
    a1 = d[0]/3;
    a3 = d[n-1]/3;
    a2 = d[n-2] - 2 *a3;
    
    cout << a1 << " " << a2 << " " << a3 << endl;
}