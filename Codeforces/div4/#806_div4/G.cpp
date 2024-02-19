#include <bits/stdc++.h>

using namespace std;

int main()
{
    cin.tie(0) -> sync_with_stdio(0);

    int t;
    cin >> t;
    for(int _; _ < t; _++){
        int n, k;
        cin >> n >> k;
        long long ans = 0;
        int arr[n];
        for(int i =0; i < n; i++){
            int num;
            cin >> num;
            arr[i] = num;
        }
        long long sum = 0;
        for(int i = -1; i < n ; i++){
            long long cur = sum;
            for(int j = i+1; j < min(n, i+32); j++){
                int a = arr[j];
                a /= 1 << (j-i);
                cur += a;
            }
            ans = max(ans, cur);
            if(i+1 != n)
                sum += arr[i+1] -k;
        }
        cout << ans << endl;
    }
}