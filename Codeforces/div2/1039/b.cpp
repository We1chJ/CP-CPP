#include "bits/stdc++.h"

using namespace std;

using ll = long long;
int main()
{
    cin.tie(0)->sync_with_stdio(0);
    int t;
    cin >> t;
    while (t--)
    {

        int n;
        cin >> n;
        vector<int> v(n);
        string ans = "";
        for (int i = 0; i < n; i++)
        {
            cin >> v[i];
        }

        vector<int> res;
        for (int i = 0; i < n / 2; i++)
        {
            res.push_back(v[i]);
            ans += 'L';
            ans += 'R';
            res.push_back(v[n - i - 1]);
        }
        if (n % 2 == 1)
        {
            res.push_back(v[n / 2]);
            if (!ans.empty() && ans.back() == 'R')
            {
                ans += 'L';
            }
            else
            {
                ans += 'R';
            }
        }
        // for (int x : res)
        // {
        //     cout << x << ' ';
        // }
        // cout << endl;
        int cnt = 1;
        int inc = 1;
        for (int i = 1; i < n; i++)
        {
            if (inc == 1)
            {
                if (res[i] > res[i - 1])
                {
                    cnt++;
                }
                else
                {
                    cnt = 2;
                    inc = 0;
                }
            }
            else
            {
                if (res[i] < res[i - 1])
                {
                    cnt++;
                }
                else
                {
                    cnt = 2;
                    inc = 1;
                }
            }
            // cout << res[i] << " " << cnt << endl;
            if (cnt >= 5)
            {
                char temp = ans[i];
                ans[i] = ans[i - 1];
                ans[i - 1] = temp;

                int te = res[i];
                res[i] = res[i - 1];
                res[i - 1] = te;

                inc = res[i] > res[i - 1];
                cnt = 2;
            }
        }
        cout << ans << endl;
    }
}