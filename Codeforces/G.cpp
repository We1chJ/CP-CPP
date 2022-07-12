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
        long long sum = 0;
        for(int i =0; i < n; i++){
            int num;
            cin >> num;
            sum += num;
            arr[i] = num;
        }
        bool flag = true;
        int cnt = 1;
        for(int i =0;i <n-1; i++){
            if(flag){
                long long val1 = arr[i] - k + arr[i+1]/2;
                long long val2 = arr[i]/2 + arr[i+1]/4;
                if(val1 < val2){
                    flag = false;
                    ans += arr[i]/2;
                    cnt++;
                }else
                    ans += arr[i] - k;
            }else{
                ans += arr[i]/(1 << cnt);
                cnt++;
            }
        }
        if(flag)
            ans += max(arr[n-1] - k, arr[n-1]/2);
        else
            ans += arr[n-1]/(1 << cnt);
        cout << ans << endl;
    }
}