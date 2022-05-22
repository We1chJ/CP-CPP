#include "bits/stdc++.h"

using namespace std;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int var = 7, foo = 8;

    int& ref = var;
    cout << &ref << " " << &var << endl;

    cout << ref << " " << &ref << " " << &foo << endl;
}