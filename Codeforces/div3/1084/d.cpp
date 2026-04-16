#include "bits/stdc++.h"

using namespace std;
using ll = long long;

int main(){
    int t;
    cin >> t;
    while(t--){
        int n, x, y;
        cin >> n >> x >> y;
        vector<int> v;
        vector<int> sorted;
        int mn = INT_MAX;
        int mnind = -1;
        for(int i = 0 ; i < n; i++){
            int a ;
            cin >> a;
            if(i >= x && i < y){
                sorted.push_back(a);
                if(a < mn){
                    mn = a;
                    mnind = sorted.size()-1;
                }
            }else{
                v.push_back(a);
            }
        }
        rotate(sorted.begin(), sorted.begin()+ mnind, sorted.end());
        // for(auto & a : sorted){
        //     cout << a << " ";
        // }
        // cout << endl;

        int ind = 0;
        while(ind < v.size() && v[ind] < sorted[0]){
            cout << v[ind] << " ";
            ind++;
        }

        for(auto & a : sorted)
        {
            cout << a << " ";
        }
        while(ind < v.size()){
            cout << v[ind] << " ";
            ind++;
        }

        cout << endl;
    }
}