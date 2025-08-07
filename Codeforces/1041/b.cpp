#include "bits/stdc++.h"

using namespace std;

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    int t;
    cin >> t;
    while (t--)
    {
        int n, x;
        cin >> n >> x;
        string s;
        cin >> s;
        int wall_count = count(s.begin(), s.end(), '#');
        x--;
        if (wall_count == 0)
        {
            cout << 1 << endl;
            continue;
        }
        int left_walls = count(s.begin(), s.begin() + x, '#');
        int right_walls = count(s.begin() + x + 1, s.end(), '#');
        int ans = INT_MAX;

        if (left_walls == 0)
        {
            // Find the first wall to the right
            int first_wall = n;
            for (int i = x + 1; i < n; ++i)
            {
                if (s[i] == '#')
                {
                    first_wall = i;
                    break;
                }
            }
            ans = min(ans, (n - first_wall) + 1);
        }
        else if (right_walls == 0)
        {
            // Find the first wall to the left
            int first_wall = -1;
            for (int i = x - 1; i >= 0; --i)
            {
                if (s[i] == '#')
                {
                    first_wall = i;
                    break;
                }
            }
            ans = min(ans, (first_wall + 1) + 1);
        }

        ans = min(ans, min(x + 1, n - x));

        cout << ans << endl;
    }
}