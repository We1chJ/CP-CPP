#include "bits/stdc++.h"

using namespace std;
unordered_map<int, int> m;

int main()
{
    stack<int> v;
    m[0] = 0;
    m[1] = 1;
    int a, b;
    while (cin >> a >> b)
    {
        int ans = 0;
        int ma = min(a, b);
        int mb = max(a, b);
        for (int i = ma; i <= mb; i++)
        {
            int n = i;
            if (m.count(n))
            {
                ans = max(ans, m[n]);
                continue;
            }
            int num = n;
            while (m.count(num) == 0 && num != 1)
            {
                v.push(num);
                if (num % 2 == 0)
                {
                    num /= 2;
                }
                else
                {
                    num = num * 3 + 1;
                }
            }

            // update the table value
            for (int x = 1; v.size() > 0; x++)
            {
                int a = v.top();
                m[a] = m[num] + x;
                v.pop();
            }
            ans = max(ans, m[n]);
        }
        cout << a << " " << b << " " << ans << endl;
    }
}