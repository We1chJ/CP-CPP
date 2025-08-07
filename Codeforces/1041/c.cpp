#include "bits/stdc++.h"

using namespace std;

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    int t;
    cin >> t;
    while (t--)
    {
        int n, k;
        cin >> n >> k;
        vector<long long> a(n), b(n);

        long long total = 0;
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        for (int i = 0; i < n; i++)
        {
            cin >> b[i];
        }
        for (int i = 0; i < n; i++)
        {
            long long ta, tb;
            ta = a[i];
            tb = b[i];
            a[i] = min(ta, tb);
            b[i] = max(ta, tb);
            total += abs(a[i] - b[i]);
        }
        vector<int> idx(n);
        for (int i = 0; i < n; i++)
            idx[i] = i;
        sort(idx.begin(), idx.end(), [&](int x, int y)
             { return a[x] < a[y]; });

        long long minIncrease = LLONG_MAX;

        for (int i = 0; i < n; i++)
        {
            // Right
            auto right = lower_bound(idx.begin(), idx.end(), i, [&](int x, int val)
                                     { return a[x] < a[val]; });
            if (right != idx.end())
            {
                right++;
                if (right != idx.end())
                {
                    int rightI = *right;
                    if (a[rightI] <= b[i])
                    {
                        minIncrease = 0;
                        break;
                    }
                    else
                    {
                        minIncrease = min(minIncrease, 2LL * (a[rightI] - b[i]));
                    }
                }
            }
            // Left (same format as right)
            auto left = lower_bound(idx.begin(), idx.end(), i, [&](int x, int val)
                                    { return a[x] < a[val]; });
            if (left != idx.begin())
            {
                left--;
                int leftI = *left;
                if (b[leftI] >= a[i])
                {
                    minIncrease = 0;
                    break;
                }
                else
                {
                    minIncrease = min(minIncrease, 2LL * (a[i] - b[leftI]));
                }
            }
        }

        cout << total + minIncrease << endl;
    }
}
