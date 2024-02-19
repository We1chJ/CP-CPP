#include "bits/stdc++.h"

using namespace std;

int main(){
    cin.tie(0) -> sync_with_stdio(0);
    int t;
    cin >> t;
    for(int i = 0; i < t; i++){
        string a;
        cin >> a;
        int cntA=0, cntB = 0;
        for(int j = 0; j < a.length();j++){
            if(a[j] == 'A')
                cntA++;
            else
                cntB++;
        }
        if(cntA > cntB)
            cout << "A" << endl;
        else
            cout << "B" << endl;
    }
}