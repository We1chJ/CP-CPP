#include "bits/stdc++.h"
using namespace std;

int arr[1000];
int main(){
    
    int n;
    cin >> n;
    for(int i = 0; i < n;i++){
        cin >> arr[i];
    }
    
    int l = 0, r = n-1;
    while(l < r){
        int mid = (l+r+1) /2;
        if(arr[mid] == 0)
            l = mid;
        else 
            r = mid-1;
    }
    cout << l << endl;

}