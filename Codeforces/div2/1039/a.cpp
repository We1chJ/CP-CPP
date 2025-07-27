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
        int n, c;
        cin >> n >> c;
        int cnt = n;
        vector<int> v;
        for (int i = 0; i < n; i++)
        {
            int a;
            cin >> a;
            if (a > c)
            {
                continue;
            }
            v.push_back(a);
        }
        sort(v.begin(), v.end());
        int mul = 1;

        for (int i = v.size() - 1; i >= 0; i--)
        {
            int a = v[i];
            if (a * mul <= c)
            {
                mul *= 2;
                cnt--;
            }
        }
        cout << cnt << endl;
    }
}