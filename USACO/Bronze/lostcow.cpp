#include "bits/stdc++.h"

using namespace std;

int main(){
    ifstream fin ("lostcow.in");    
    ofstream fout ("lostcow.out");

    int x, y;
    fin >> x >> y;

    int ans = 0;

    int i = 0;

    while(true){
        if((x < y && x + (i%2 == 1 ? -1 : 1)*(1 << i) >= y) || (x > y && x + (i%2 == 1 ? -1 : 1)*(1 << i) <= y)){
            ans += abs(x - y);
            break;
        }
        ans += 2*(1 << i);
        i++;        
    }

    fout << ans << endl;
}