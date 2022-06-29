#include "bits/stdc++.h"

using namespace std;

int k = 19;
int anc[200001][19];

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, q;
    cin >> n >> q;

    for(int i = 2; i <= n; i++){
        int num = 0;
        cin >> num;
        anc[i][0] = num;
    }
    
    for(int j = 1; j < k; j++){
        for(int i = 2; i <= n; i++){
            anc[i][j] = anc[anc[i][j-1]][j-1];
        }
    }
    for(int i = 0; i < q; i++){
        int a, c;
        cin >> a >> c;
        for(int j = 0; j < k; j++){
            if((c >> j) & 1){
                a = anc[a][j];
            }
        }
        if(a == 0)  a = -1;
        cout << a << endl;
    }    
}