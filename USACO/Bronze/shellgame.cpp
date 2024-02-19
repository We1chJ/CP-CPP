#include "bits/stdc++.h"
using namespace std;
#define f first
#define s second
#define pb push_back

int main(){
    cin.tie(0) -> sync_with_stdio(0);
    freopen("shell.in", "r", stdin);
    freopen("shell.out", "w", stdout);

    int n; 
    cin >> n;
    int pos[3] = {1, 2, 3};
    int ans[3] = {0, 0, 0};
    for(int i = 0; i< n; i++){
        int a, b, g;
        cin >> a >> b >> g;
        for(int j = 0; j < 3 ; j++){
            if(pos[j] == a){
                pos[j] = b;
            }else if(pos[j] == b){
                pos[j] = a;
            }            

            if(g == pos[j])
                ans[j] ++;
        }
    }

    cout << max(ans[0], max(ans[1], ans[2])) << endl;

}