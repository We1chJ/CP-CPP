#include "bits/stdc++.h"

using namespace std;
const int TEST = 2000+1;

vector<int> adj[TEST];
set<int> ee[26];

struct Op{
    int index;
    char letter;
    string replaced;
};

vector<Op> op;
vector<bool> visited(TEST);

void construct(int cur){
    char letter = op[cur].letter;
    string replaced = op[cur].replaced;
    for(int i = 0; i < replaced.length(); i++){
        if(ee[(int)replaced[i] - 97].upper_bound(cur) != ee[(int)replaced[i] - 97].end()){
            int nxt = *ee[(int)replaced[i] - 97].upper_bound(cur);
            adj[cur].push_back(nxt);
            construct(nxt);
        }else{
            if(visited[cur]) continue;
            adj[cur].push_back(-1);
        }
    }
    visited[cur] = true;
}

string dfs(int cur){
    char letter = op[cur].letter;
    string replaced = op[cur].replaced;
    string temp = "";
    int ptr = 0;
    for(auto a : adj[cur]){
        if(a == -1)
            temp = temp + replaced[ptr];
        else
            temp = temp + dfs(a);
        ptr++;
        
    }
    return temp;
}



int main(){
    cin.tie(0)->sync_with_stdio(0);
    int l, r, operations;
    cin >> l >> r >> operations;
    
    op.push_back({0, 'a', "a"});
    for(int i = 1; i <= operations; i++){
        char letter;
        string replaced;
        cin >> letter >> replaced;
        op.push_back({i, letter, replaced});
        ee[(int)letter-97].insert(i);
    }
    construct(0);
    string res = dfs(1);
    cout << res.substr(l-1, r) << endl;
}