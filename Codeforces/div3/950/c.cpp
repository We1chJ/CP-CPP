#include "bits/stdc++.h"
using namespace std;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<int> v(n);
        for(int i = 0; i < n; i++){
            cin >> v[i];
        }

        unordered_set<int> f;

        vector<int> after(n);
        for(int i = 0; i < n ; i++){
            cin >> after[i];
            f.insert(after[i]);
        }
        int m;
        cin >> m;
        vector<int> op (m);
        for(int i = 0; i < m; i++){
            int a;
            cin >> op[i];
        }
        // ==================

        unordered_multiset<int> seq;
        for(int i = 0 ; i < n; i ++){
            if(v[i] != after[i])
                seq.insert(after[i]);
        }
        vector<int> st;
        for(int i = 0 ; i < m; i++){
            int a = op[i];
            if(seq.count(a)){
                seq.extract(a);
                st.clear();
            }else{
                if(f.count(a))
                    st.clear();
                else st.push_back(a);
            }
        }

        // for(auto & a : st){
        //     if(f.count(a) == 0){
        //         goto no;
        //     }
        // }

        if(st.size() || seq.size()){
            no:
            cout << "NO" << endl;
        }else{
            cout << "YES" << endl;
        }
               
    }
}