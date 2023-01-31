#include "bits/stdc++.h"

using namespace std;

int main(){

    cin.tie(0)->sync_with_stdio(0);

    int l, r, operation;
    cin >> l >> r >> operation;

    vector<char> fir(l-1, '-');
    vector<char> sec(r-l+1, '-');

    fir[0] = 'a';

    for(int i = 0; i < operation; i++){
        char original;
        string replaced;
        cin >> original >> replaced;

        queue<char> q;
        // update fir
        for(int j = 0; j < l-1; j++){
            if(fir[j] == original){
                for(int a = 0; a < replaced.length(); a++)
                    q.push(replaced[a]);
            }else if(fir[j] != '-')
                q.push(fir[j]);
            if(!q.empty()){
                fir[j] = q.front();
                q.pop();
            }
            if(q.empty() && fir[j] == '-') break;
        }

        // uppdate sec

        if(q.empty()) continue;

        for(int j = 0; j <= r-l; j++){
            if(sec[j] == original){
                for(int a = 0; a < replaced.length(); a++)
                    q.push(replaced[a]);
            }else if(sec[j] != '-')
                q.push(sec[j]);
            if(!q.empty()){
                sec[j] = q.front();
                q.pop();
            }
            if(q.empty() && sec[j] == '-') break;
        }
    } 
    
    for(auto a : sec){
        cout << a;
    }
    cout << endl;
}



/*
Solutions:

only need substring from (0, r)

backtrace?


hanle 0-l and l-r separately


*/