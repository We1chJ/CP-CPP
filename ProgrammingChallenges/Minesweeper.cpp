#include "bits/stdc++.h"

using namespace std;

int main() {
    int x[] = {-1, 0, 1};
    int y[] = {-1, 0, 1};


    int n, m;
    while(cin >> n >> m){
        vector<string> v(n);
        for(int i = 0; i < n; i++){
            cin >> v[i];
        }

        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(v[i][j] == '.')
                    v[i][j] = '0';
                if(v[i][j] == '*'){
                    for(int a = 0; a < 3; a++){
                        for(int b = 0; b < 3; b++){
                            int inew = i + x[a];
                            int jnew = j + y[b];
                            if(inew >= 0 && inew < n && jnew >= 0 && jnew < m && v[inew][jnew] != '*'){
                                if(v[inew][jnew] == '.')
                                    v[inew][jnew] = '0';
                                
                                v[inew][jnew] = (v[inew][jnew] - '0' + 1 )+ '0';
                            }
                        }
                    }
                }
            }
        }

        for(int i = 0; i < n; i++){
            cout << v[i] << endl;
        }
    }

}