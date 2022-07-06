#include "bits/stdc++.h"

using namespace std;

int n, m;

int color[1000][1000];

int ans[1000][1000][2][4];

struct info{
    int x, y, org, dir, dis;
    info (int x, int y, int org, int dir):
        x(x), y(y), org(org), dir(dir){
    }
};

int row[4] = {-1, 1, 0, 0};
int col[4] = {0, 0, -1, 1};

bool valid(int x, int y, int dir){
    return  x + row[dir] >= 0 && x + row[dir] < n && y + col[dir] >= 0 && y + col[dir] < m;
}

int main(){
    // cin.tie(0) -> sync_with_stdio(0);
    freopen("dream.in", "r", stdin);
    freopen("dream.out", "w", stdout);
    cin >> n >> m;

    for(int i =0 ; i < n ;i ++){
        for(int j = 0; j < m; j++){
            cin >> color[i][j];
            for(int a = 0; a < 2; a++)
                for(int b = 0; b < 4; b ++) 
                    ans[i][j][a][b] = -1;
        }
    }
    
    ans[0][0][0][0] = 0;
    queue<info> q;
    q.push(info(0, 0, 0, 0));
    while(!q.empty()){
        info in = q.front();
        q.pop();
        int x = in.x, y = in.y, org = in.org, dir = in.dir;
        int c = color[x][y];
        if(x == n-1 && y == m - 1) {cout << ans[x][y][org][dir] << endl; return 0;}

        if(c == 4 && valid(x, y, dir)){
            if(ans[x + row[dir]][y + col[dir]][org][dir] != -1) continue;
            else if(color[x + row[dir]][y + col[dir]] != 0  && color[x + row[dir]][y + col[dir]] != 3){
                ans[x + row[dir]][y + col[dir]][org][dir] = ans[x][y][org][dir] + 1;

                info nxt = info(x + row[dir], y + col[dir], org, dir);
                nxt.dis = ans[x + row[dir]][y + col[dir]][org][dir];
                q.push(nxt);
                continue;
            }
        }

        for(int i = 0; i < 4; i++){
            if(valid(x, y, i)){
                int nxtCol = color[x + row[i]][y + col[i]];
                info nxt = info(x + row[i], y + col[i], org, i);
                if(nxtCol == 0) continue;
                if(nxtCol == 2) nxt.org = 1;
                if(nxtCol == 3 && org != 1) continue;
                if(nxtCol == 4) nxt.org = 0;
                if(ans[nxt.x][nxt.y][nxt.org][nxt.dir] != -1) continue;
                ans[nxt.x][nxt.y][nxt.org][nxt.dir] = ans[x][y][org][dir] + 1;

                nxt.dis = ans[nxt.x][nxt.y][nxt.org][nxt.dir];

                q.push(nxt);
            }
        }        
    }

    cout << -1 << endl;
}