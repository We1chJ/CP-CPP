#include "bits/stdc++.h"
using namespace std;

int main(){
    cin.tie(0)->sync_with_stdio(0);

    int t;
    cin >>t;
    
    while(t--){
        long double n, p;
        cin >> n >> p;

        long double ans = 0.0;

        long double sum = 0;
        for(int i = 0; i < n; i++){
            long long a;
            cin >> a;
            sum += a;
        }

        ans = (p*p)/sum;


        cout << setprecision(10)<< ans <<"\n";
    }
    

}