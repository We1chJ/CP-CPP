#include "bits/stdc++.h"
using namespace std;

int main(){

    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;

        bool a = false,b = false, c = false, d = false;
        for(int i = 0; i <n; i++){
            int num;
            cin >>num;
            if(num <= 10) a= true;
            else if(num <= 20) b = true;
            else if (num <= 30) c = true;
            else if (num <= 40) d = true;

        }
        cout << a+b+c+d << endl;

    }

}