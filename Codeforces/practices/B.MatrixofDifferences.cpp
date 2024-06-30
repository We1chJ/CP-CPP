#include "bits/stdc++.h"
using namespace std;

int main(){

    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;

        int arr[n][n];
        int x = n*n;
        int y = 1;

        vector<int> v;
        while(x >= y){
            v.push_back(x--);
            v.push_back(y++);
        }
        int count = 0;
        for(int i = 0; i < n; i++){
            if(i %2 == 0){
                for(int j = 0; j < n; j++){
                    arr[i][j] = v[count++];
                }
            }else{
                for(int j = n-1; j >= 0; j--)
                    arr[i][j] = v[count++];
            }
        }

        for(int i  =0 ; i < n ; i++){
            for(int j = 0; j < n; j++){
                cout << arr[i][j] << " ";
            }
            cout << endl;
        }
    }

}