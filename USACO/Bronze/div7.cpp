#include "bits/stdc++.h"

using namespace std;

int main(){
    ifstream fin ("div7.in");    
    ofstream fout ("div7.out");
    cin.tie(0)->sync_with_stdio(0);

    int n;
    fin >> n;
    vector<int> v(n);
    for(int i=0 ; i <n; i++){
        int a ; 
        fin >> a;
        v[i] = a%7;
    }

    vector<int> ind(7, -1);
    int ans = 0;
    int num = 0;
    for(int i = 0; i < n; i++){
        num += v[i];
        num %= 7;
        if(num == 0) ans = max(i+1, ans);
        else{
            if(ind[num] != -1){
                ans = max(ans, i - ind[num]);
            }else{
                ind[num] = i;
            }
        }
    }

    fout << ans << endl;

}