#include "bits/stdc++.h"

using namespace std;

int c[100000];
int main(){
    freopen("cbarn.in", "r", stdin);
    freopen("cbarn.out", "w", stdout);
    int n;
    cin >> n ;
    int sum = 0, lowest = INT_MAX, lowestInd = -1;
    for(int i = 0; i < n ; i++)
        cin >> c[i];
    for(int i = 0; i < n ; i++){
        sum += c[i] - 1;
        if(sum < lowest){
            lowest = sum;
            lowestInd = i;
        }
    }
    
    int start = lowestInd+1;
    long long ans = 0;
    rotate(c, c + start, c + n);
    int ptr = 0;
    vector<int> cnt(n);
    for(int i = 0; i < n; i ++){
        cnt[i] += c[i];
        while(cnt[ptr] == 0) ptr++;
        cnt[ptr]--;

        ans += (i - ptr) *(i- ptr);
    }

    cout << ans << "\n";
}