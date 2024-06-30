#include "bits/stdc++.h"

using namespace std;

int gcd(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

int main(){
    cin.tie(0)->sync_with_stdio(0);

    int t;
    cin >>t ;
    while(t--){
        int n;
        cin >> n;
        vector<int> a(n);
        for(int i = 0; i < n; i ++){
            cin >> a[i];
        }
        int prev = -1;
        int ind = -1;
        for(int i = 0 ; i < n-1; i++){
            int cur = (gcd(a[i], a[i+1]));
            if(prev > cur){
                ind = i;
                break;
            }
            prev = cur;
        }
        if(ind == -1)
            cout << "YES" << endl;
        else{
            // vector<int> v1 (a);
            // v1.erase(v1.begin() + ind-1);
            // vector<int> v2 (a);
            // v2.erase(v2.begin() + ind);
            // vector<int> v3 (a);
            // v3.erase(v3.begin() + ind+1);

            vector<int> v[3];
            v[0] = v[1] = v[2] = vector<int>(a);
            v[0].erase(v[0].begin() + ind-1);
            v[1].erase(v[1].begin() + ind);
            v[2].erase(v[2].begin() + ind+1);
            
            bool works = false;
            for(int c = 0; c < 3; c++){
                int prev = -1;
                for(int i = 0; i < n-2; i++){
                    int cur = gcd(v[c][i], v[c][i+1]);
                    if(cur < prev){
                        works = false;
                        break;
                    }else
                        works = true;
                    prev = cur;
                }   
                if(works){
                    break;
                }
            }
            
            cout << (works ? "YES" : "NO") << endl;
        }


        
    }
}