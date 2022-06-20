#include "bits/stdc++.h"

using namespace std;

vector<int> v;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    for(int i = 0; i < n ; i++){
        int num;
        cin >> num;
        int pos = lower_bound(v.begin(), v.end(), num) - v.begin();
        if(pos == v.size()) v.push_back(num);
        else v[pos] = num;
    }

    cout << v.size() << endl;

    return 0;
}