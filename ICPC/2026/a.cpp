#include "bits/stdc++.h"
using namespace std;

int main(){

    long long n;
    cin >>n;

    // sum{1}{n} i(i+1)/2 --> sum{1}{n}i^2/2 + sum{1}{n}i/2
    // n(n+1)(2n+1)/12 + n(n+1)/4
    // 

    long long MOD = 998244353;
    n %= MOD;
    long long ans = n*(n+1)%MOD * (n+2)%MOD;

    long long inv6 = 1;
    long long base = 6;
    long long exponent = MOD - 2;
    while (exponent > 0) {
        if (exponent & 1) inv6 = inv6 * base % MOD;
        base = base * base % MOD;
        exponent >>= 1;
    }
    ans = ans * inv6 % MOD;

    cout << ans << endl;

}