#include "bits/stdc++.h"

using namespace std;
using ll = long long;
ll dp[1001][1001];
string strn, strm;


ll dis[1001][1001];

int col[] = {-1, 1, 0, 0};
int row[] = {0, 0, -1, 1};

ll d(int ax, int ay, int bx, int by){
    return abs(ax - bx) * abs(ax - bx) + abs(ay - by) * abs(ay - by);
}

int main(){

    freopen("radio.in", "r", stdin);
    freopen("radio.out", "w", stdout);
    int n, m;
    cin >> n >> m;
    int nx, ny, mx, my;
    cin >> nx >> ny >> mx >> my;
    
    cin >> strn >> strm;
    int curnx, curny, curmx, curmy;
    curnx = nx, curny = ny, curmx = mx, curmy = my;
    for(int i = 0; i <= n; i++){
        if(i != 0){
            if(strn[i-1] == 'N') { curnx += row[0]; curny += col[0];}
            if(strn[i-1] == 'S') { curnx += row[1]; curny += col[1];}
            if(strn[i-1] == 'W') { curnx += row[2]; curny += col[2];}
            if(strn[i-1] == 'E') { curnx += row[3]; curny += col[3];}
        }
        curmx = mx, curmy = my;
        for(int j = 0; j <= m; j++){
            if(j != 0){
                if(strm[j-1] == 'N') { curmx += row[0]; curmy += col[0];}
                if(strm[j-1] == 'S') { curmx += row[1]; curmy += col[1];}
                if(strm[j-1] == 'W') { curmx += row[2]; curmy += col[2];}
                if(strm[j-1] == 'E') { curmx += row[3]; curmy += col[3];}
            }
            dis[i][j] = d(curnx, curny, curmx, curmy);
        }
    }
    for(int i = 0; i <= n; i++){
        for(int j = 0; j <= m; j++)
            dp[i][j] = INT64_MAX;
    }
    dp[0][0] = 0;
    dis[0][0] = 0;
    for(int i = 0; i <= n ; i++){
        for(int j = 0 ; j <= m; j++){
            ll cur = dp[i][j];
            if(j+1<= m) dp[i][j+1] = min(dp[i][j+1], cur + dis[i][j+1]);
            if(i+1<= n) dp[i+1][j] = min(dp[i+1][j], cur + dis[i+1][j]);
            if(i + 1 <= n && j + 1 <= m) dp[i+1][j+1] = min(dp[i+1][j+1], cur + dis[i+1][j+1]);
        }
    }
    cout << dp[n][m] << endl;
    
}