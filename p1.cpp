#include "bits/stdc++.h"
using namespace std;

using ll = long long;

int n;
vector<ll> a (501);

vector<ll> prefix(501);

vector<ll> notInclude;
vector<ll> include;

vector<tuple<int, int, ll>> allSum;

ll findMinDiff(){
    int l = 0, r = 0;
    ll res = INT_FAST64_MAX;

    while(l < notInclude.size() && r < include.size()){
        ll dif = abs(notInclude[l] - include[r]);
        res = min(res, dif);
        if(notInclude[l] < include[r])
            l++;
        else 
            r++;
    }
    return res;
}


int main(){
    cin.tie(0)->sync_with_stdio(0);

    cin >> n;
    for(int i =1 ; i <= n; i ++){
        cin >> a[i];
    }

    // compute the prefix sum
    prefix[0] = 0;
    for(int i = 1; i <= n; i++){
        prefix[i] = prefix[i-1] + a[i];
    }

    for(int i = 1; i <= n; i++){
        for(int j = i; j <= n; j++){
            ll sum = prefix[j] - prefix[i-1];
            allSum.push_back({i, j, sum});
            // cout << sum << " ";
        }
    }

    for(int i = 1; i <= n; i++){
        notInclude.clear();
        include.clear();
        for(auto a : allSum){
            int l, r, sum;
            tie(l, r, sum) = a;
            if(i >= l && i <= r)
                include.push_back(sum);
            else 
                notInclude.push_back(sum);
        }
        sort(include.begin(), include.end());
        sort(notInclude.begin(), notInclude.end());
        // cout << "breakpoknt";
        cout << findMinDiff() << endl;
    }



}