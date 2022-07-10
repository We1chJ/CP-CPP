#include "bits/stdc++.h"

using namespace std;

using ll = long long;

int n;
pair<ll, ll> cows[50001];
auto cmpY = [](const int& x, const int& y) { return cows[x].second == cows[y].second ? cows[x].first < cows[y].first : cows[x].second < cows[y].second;};
auto cmpX = [](const int& x, const int& y) { return cows[x].first == cows[y].first ? cows[x].second < cows[y].second : cows[x].first < cows[y].first;};

ll solve1(){
    ll ans = INT64_MAX;
    vector<int> v(n);
    ll leftX = INT64_MAX;
    ll rightX = 0;
    for(int i = 0; i < n ; i++){
        v[i] = i;
        leftX = min((ll)cows[i].first, leftX);
        rightX = max((ll)cows[i].first, rightX);
    }
    sort(v.begin(), v.end(), cmpX);
    set<int,bool(*)(const int&,const int&)> s1(cmpY), s2(cmpY);
    for(auto a : v){
        s2.insert(a);
    }
    
    for(int i = 0; i < n-1 ; i++){
        ll curX = cows[v[i]].first;
        ll nextX = cows[v[i+1]].first;
        s1.insert(v[i]);
        s2.erase(v[i]);
        ans = min(ans, (curX - leftX) * (cows[*--s1.end()].second - cows[*s1.begin()].second) + (rightX - nextX) * (cows[*--s2.end()].second - cows[*s2.begin()].second));
    }
    return ans;
}

ll solve2(){
    ll ans = INT64_MAX;
    vector<int> v(n);
    ll botY = INT64_MAX;
    ll topY = 0;
    for(int i = 0; i < n ; i++){
        v[i] = i;
        botY = min((ll)cows[i].second, botY);
        topY = max((ll)cows[i].second, topY);
    }
    sort(v.begin(), v.end(), cmpY);
    set<int,bool(*)(const int&,const int&)> s1(cmpX), s2(cmpX);
    for(auto a : v){
        s2.insert(a);
    }
    for(int i = 0; i < n-1 ; i++){
        ll curY = cows[v[i]].second;
        ll nextY = cows[v[i+1]].second;
        s1.insert(v[i]);
        s2.erase(v[i]);
        ans = min(ans, (curY - botY) * (cows[*--s1.end()].first - cows[*s1.begin()].first) + (topY - nextY) * (cows[*--s2.end()].first - cows[*s2.begin()].first));
    }
    return ans;
}

int main(){
    freopen("split.in", "r", stdin);
    freopen("split.out", "w", stdout);
    cin >> n;
    ll top, bot, left, right;
    top = right = 0;
    bot = left = INT64_MAX;
    for(int i = 0; i < n ; i++){
        ll a, b;
        cin >> a >> b;
        cows[i] = {a, b};
        top = max(top, b);
        bot = min(bot, b);
        left = min(left, a);
        right = max(right, a);
    }
    ll one = (top - bot) * (right - left);
    cout << (one - min(solve1(), solve2())) << endl;
}