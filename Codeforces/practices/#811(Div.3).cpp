#include "bits/stdc++.h"
using namespace std;
#define len(s) (int) s.size()
bool found;
int ans;


void find(int st, int en, string &s, vector<string> &v, vector<pair<int, int>> &match){
    int Max = 0, id = -1, pos = -1;
    for(int i = st; i <= en; i++){
        for(int j = 0; j < len(v); j++){
            string str = v[j];
            if(i + len(str) > len(s) || i + len(str) <= en) continue;
            if(s.substr(i, len(str)) == str){
                if(i + len(str) > Max){
                    Max = i + len(str);
                    id = j;
                    pos = i;
                }
            }
        }
    }
    if(id == -1){
        found = false;
        return;
    }else{
        match.push_back({id, pos});
        ans++;
        if(Max == len(s)) return;
        else find(en + 1, Max, s, v, match);
    }
}

int main(){
    int t;
    cin >> t;
    while(t--){
        found = true;
        ans = 0;
        string s;
        cin >> s;
        int n ;
        cin >> n;
        vector<string> v(n);
        for(int i = 0; i < n ;i ++){
            cin >> v[i];
        }
        vector<pair<int, int>> match;
        find(0, 0, s, v, match);
        if(!found) cout << -1 << endl;
        else{
            cout << ans << endl;
            for(auto a: match) cout << a.first+1 << " " << a.second+1 << endl;
        } 
    }
}