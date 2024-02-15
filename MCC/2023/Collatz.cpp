/*

simulation

*/

#include "bits/stdc++.h"

using namespace std;

using ll = long long;

int main(){
    freopen("1-collatz/input7.txt", "r", stdin);
    int n, k;
    cin >> n >> k;
    int sum = 0;
    for(int i = 0; i < n;i++){
        int num;
        cin >> num;

        for(int j = 0; j < k; j++){
            if(num%2==0)
                num /=2;
            else
                num = 3*num+1;
        }
        sum += num;
    }

    cout << sum << endl;  
}