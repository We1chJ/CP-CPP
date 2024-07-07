#include "bits/stdc++.h"

using namespace std;
vector<int> ans, v;


void floyd(int cur){
    int a = v[cur];
    int b = v[v[cur]];

    while(a != b){
        
        if(ans[a] != 0){
            int t = cur;
            while(t != a){
                ans[t] = ans[a];
                t = v[t];
            }
            return ;
        }

        a = v[a];
        b = v[v[b]];
    }
    a = cur;

    while(a != b){
        a = v[a];
        b = v[b];
    }

    int entry = a; 
    a = cur;
    while(a != entry){
        ans[a] = entry;
        a = v[a];
    }
    a = entry;
    do {
        ans[a] = a;
        a = v[a];
    } while(a!=entry);
}

int main(){

    int n ;
    cin >> n;

    ans.resize(n+1, 0);
    v.resize(n+1);
    for(int i = 1 ; i <= n;i++){
        cin >> v[i];
    }

    for(int i = 1; i <= n; i++){
        if(ans[i] == 0) floyd(i);
    }

    for(int i = 1; i <= n;i++){
        cout << ans[i] << " ";
    }
    cout << endl;
}