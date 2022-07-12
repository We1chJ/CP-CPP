#include "bits/stdc++.h"

using namespace std;

int main(){

    cin.tie(0) -> sync_with_stdio(0);

    int t;
    cin >> t;
    for(int a = 0; a < t; a++){
        int n;
        cin >> n;
        int arr[n];
        for(int i = 0 ;i  < n; i++)
            cin >> arr[i];
        for(int i = 0; i < n; i++){
            int cnt;
            cin >> cnt;
            string code;
            cin >> code;
            for(int j = 0; j < cnt; j++){
                if(code[j] == 'D'){
                    arr[i] = (arr[i] +1)%10;
                }else{
                    arr[i] = (arr[i] -1 + 10)%10;
                }
            }
        }
        for(auto x : arr){
            cout << x << " ";
        }
        cout << endl;
    }
}