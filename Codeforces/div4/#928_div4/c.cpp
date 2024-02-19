#include "bits/stdc++.h"
using namespace std;

int N = 2*1e5 +1;
vector<int> digSum (N);

int main(){
    cin.tie(0)->sync_with_stdio(0);

    digSum[0] = 0;
    for(int i = 1; i < N; i++){
        int num = i;
        digSum[i] = 0;
        while(num != 0){
            digSum[i] += num%10;
            num /= 10;
        }
        digSum[i] += digSum[i-1];
    }

    int t;
    cin >> t;
    while(t--){
        int n ;
        cin >> n;
        cout << digSum[n] << endl;

    }
}