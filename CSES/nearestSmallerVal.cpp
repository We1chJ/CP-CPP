#include "bits/stdc++.h"

using namespace std;

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    int arr[n+1];
    for(int i = 0; i < n; i++){
        cin  >> arr[i+1];
    }
    stack<int> s;
    for(int i = 1; i <= n; i++){
        int num = arr[i];
        while(!s.empty() && arr[s.top()] >= num) s.pop();

        if(s.empty()) cout << 0 << " ";
        else cout << s.top() << " ";
        s.push(i);
    }


}