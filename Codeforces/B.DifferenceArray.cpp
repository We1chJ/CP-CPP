#include "bits/stdc++.h"
using namespace std;


vector<int> v (100001);

int main(){

    cin.tie(0) -> sync_with_stdio(0);
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        for(int i = 0; i < n ; i++){
            int a ;
            cin >> a;
            v[i] = a;
        }
        for(int i = n-2; i>=0; i--){
            int prev = v[i+1];
            bool ok = false;
            for(int j = i; j >= 0;j--){
                ok = (v[j] == 0);
                int temp = v[j];
                v[j] = prev - v[j];
                prev = temp;
                if(ok){
                    sort(v.begin() + j, v.begin() + i + 1);
                    break;
                }
            }
            if(!ok){
                sort(v.begin(), v.begin()+i+1);
            }
        }
        cout << v[0] << endl;
    }
}