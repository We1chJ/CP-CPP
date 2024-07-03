#include "bits/stdc++.h"

using namespace std;

int arr[1001][1001];
int n, m;

void ff(int x, int y){
    if(x < 0 || x >= n || y < 0 || y >=  m || arr[x][y] != 1)
        return ;
    
    arr[x][y] = 2;
    ff(x+1, y);
    ff(x-1, y);
    ff(x, y+1);
    ff(x, y-1);

}
int main(){
    cin >> n >> m;
    for(int i = 0; i < n ; i++){
        string s;
        cin >> s;
        for(int j = 0; j < m; j++){
            if(s[j] == '#')
                arr[i][j] = -1;
            else
                arr[i][j] = 1;
        }
    }

    int cnt = 0;
    for(int i =0 ; i < n ; i++){
        for(int j = 0; j< m; j++){
            if(arr[i][j] == 1){
                ff(i, j);
                cnt++;
            }
        }
    }

    cout << cnt << endl;
    
}

