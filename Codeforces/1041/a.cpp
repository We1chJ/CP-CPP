#include "bits/stdc++.h"

using namespace std;

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
        unordered_set<int> s;
        for (int i = 0; i < n; i++)
        {
            cin >> v[i];
            if (v[i] != -1){
                s.insert(v[i]);
            }
        }
        bool success = true;

        if (s.size() > 1) {
            success = false;
        }
        else if(s.size() == 1 && *s.begin() == 0){
            success = false;
        }

        cout << (success ? "yes" : "no") << endl;
    }
}