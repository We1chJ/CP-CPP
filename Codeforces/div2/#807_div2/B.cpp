#include "bits/stdc++.h"

using namespace std;

using ll = long long;
int main(){
    cin.tie(0) -> sync_with_stdio(0);

    int t;
    cin >> t;
    for(int _ = 0; _ < t; _++){
        int n;
        cin >> n;
        ll arr[n];
        ll sum = 0;
        int ptr1 = -1;
        int cnt = 0;
        for(int i = 0; i < n ; i++){
            cin >> arr[i];
            sum += arr[i];
            int num = arr[i];
            if(ptr1 == -1 && num > 0) ptr1 = i;
            if(ptr1 != -1 && num == 0 && i != n-1) cnt ++;
        }
        cout << cnt + sum - arr[n-1] << endl;       
        
    } 
}