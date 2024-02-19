#include "bits/stdc++.h"

using namespace std;

int main(){

    cin.tie(0) -> sync_with_stdio(0);

    int t;
    cin >> t;
    for(int a = 0; a < t; a++){
        int n;
        cin >> n;
        int arr[n][n];
        bool visited[n][n];
        for(int i = 0 ; i < n ; i++){
            string s;
            cin >> s;
            for(int j = 0; j < n ;j++){
                arr[i][j] = s[j] - 48;
                visited[i][j] = false;
            }
        }

        int ans = 0;
        for(int i = 0; i < n ; i++){
            for(int j = 0; j < n; j++){
                if(visited[i][j]) continue;
                int cnt = 0;
                if(arr[i][j] == 1)cnt++;
                if(arr[n-j-1][i] == 1) cnt++;
                if(arr[j][n-i-1] == 1) cnt ++;
                if(arr[n-i-1][n-j-1] == 1) cnt++;
                ans += min(4 - cnt, cnt);
                visited[i][j] = true;
                visited[n-j-1][i] = true;
                visited[j][n-i-1] = true;
                visited[n-i-1][n-j-1] = true;
            }
        }
        cout << ans << endl;
    }
}