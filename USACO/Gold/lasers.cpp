// cringe, better use java

#include "bits/stdc++.h"

using namespace std;

struct Line
{
    int val;
    bool horizontal;
};

Line make(int val, bool b)
{
    Line l = {val, b};
    return l;
}

struct line_hash {
    size_t operator() (const Line& a) const { 
        int prime = 31;
        int result = 1;
        result = prime * result + (a.horizontal ? 1231 : 1237);
        result = prime * result + a.val;
        return result;
    }
};

struct line_equal {
    bool operator() (const Line& a, const Line& b) const {
        if (a.horizontal != b.horizontal)
            return false;
        if (a.val != b.val)
            return false;
        return true;
    }
};


int main()
{
    freopen("lasers.in", "r", stdin);
    freopen("lasers.out", "w", stdout);
    cin.tie(0)->sync_with_stdio(0);
    int n, x1, y1, x2, y2;
    cin >> n >> x1 >> y1 >> x2 >> y2;
    queue<Line> q;
    unordered_map<Line, int, line_hash, line_equal> dist;
    dist[make(y1, true)] = 0;
    dist[make(x1, false)] = 0;
    q.push(make(x1, false));
    q.push(make(y1, true));

    unordered_map<int, vector<int>> xToy;
    unordered_map<int, vector<int>> yTox;
    for (int i = 0; i < n; i++)
    {
        int x, y;
        cin >> x >> y;
        if (xToy.count(x) == 0)
        {
            vector<int> temp;
            xToy[x] = temp;
        }
        xToy[x].push_back(y);
        if (yTox.count(y) == 0)
        {
            vector<int> temp;
            yTox[y] = temp;
        }
        yTox[y].push_back(x);
    }

    int ans = -1;
    while (!q.empty())
    {
        Line cur = q.front();
        q.pop();

        if (cur.horizontal && cur.val == y2)
        {
            ans = dist[cur];
            break;
        }

        if (!cur.horizontal && cur.val == x2)
        {
            ans = dist[cur];
            break;
        }

        unordered_map<int, vector<int>> list = cur.horizontal ? yTox : xToy;
        if (list.count(cur.val))
        {
            for (auto a : list[cur.val])
            {
                Line nxt = make(a, !cur.horizontal);
                if (!dist.count(nxt))
                {
                    dist[nxt] = dist[cur] + 1;
                    q.push(nxt);
                }
            }
        }
    }

    cout << ans << endl;
}