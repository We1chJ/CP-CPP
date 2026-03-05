#include "bits/stdc++.h"
using namespace std;


int main(){
    ifstream fin ("bcount.in");    
    ofstream fout ("bcount.out");

    int n, q;
    fin >> n >> q;
    // 3xN
    vector<vector<int>> ps (4, vector<int> (n+1,0));

    for(int i = 1; i <=n ;i ++){
        int type ;
        fin >> type;
        
        for(int a = 1; a <= 3; a++){
            ps[a][i] = ps[a][i-1]; // populate the prefix sums
            if(a == type) ps[type][i]++;
        }
        

    }

    for(int i  = 0; i < q; i++){
        int l, r;
        fin >> l >> r;

        fout << ps[1][r] - ps[1][l-1] << " " <<  ps[2][r] - ps[2][l-1] << " " <<  ps[3][r] - ps[3][l-1] << endl;
    }


}