#include "bits/stdc++.h"
using namespace std;

using ll = long long;

struct Foo{
    int l, w, pos;
};
bool cmp(const Foo& x, const Foo& y) { return x.l < y.l; }

vector<string> v(11);
vector<int> oc (101);
int main(){
    cin.tie(0) -> sync_with_stdio(0);
    int t;
    cin >> t;
    here : while(t--){
        string str;
        cin >> str;
        int n;
        cin >> n;
        
        for(int i = 0; i < n ; i++){
            cin >> v[i];
        }
        for(int i = 0; i < str.size(); i++)
            oc[i] = 0;

        vector<Foo> p;
        for(int a = 0; a < n; a++){
            string s = v[a];
            for(int i = 0; i < str.size(); i++){
                if(i + s.length() <= str.size() && s == str.substr(i,s.length())){
                    for(int j = i; j < i + s.length(); j++)
                        oc[j] ++;
                    Foo f;
                    f.l = s.length();
                    f.pos = i;
                    f.w = a;
                    p.push_back(f);
                }
            }
        }

        for(int i = 0; i < str.length(); i++){
            int a = oc[i];
            if(a == 0){
                cout << -1 << endl;
                goto here;
            }
        }
        sort(p.begin(), p.end(), cmp);
        string ans = "";
        int cnt = 0;
        for(auto a : p){
            bool done = false;
            for(int i = a.pos; i < a.pos + a.l; i++){
                if(oc[i] == 1){
                    ans += to_string(a.w+1)  +  " " + to_string(a.pos+1) + "\n";
                    cnt ++;
                    done = true;
                    break;
                }
            }
            if(done) continue;
            for(int i = a.pos; i < a.pos + a.l; i++){
                oc[i]--;
            }
        }
        cout << cnt  << endl;
        cout << ans;
    }
}