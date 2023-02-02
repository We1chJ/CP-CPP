#include "bits/stdc++.h"

using namespace std;
int n;
int dp[20][20][4][20][20][4];
int graph[20][20];

const int dx[] = {-1,0,1,0};
const int dy[] = {0,1,0,-1};

class State{
    public :
        int ax, ay, ad;
        int bx, by, bd;
        
        State(int ax1, int ay1, int ad1, int bx1, int by1, int bd1) {
            ax = ax1;
            ay = ay1;
            ad = ad1;
            bx = bx1;
            by = by1;
            bd = bd1;
        }

        State turnLeft() {
			return State(ax, ay, (ad+3)%4, bx, by, (bd+3)%4);
		}

		State turnRight() {
			return State(ax, ay, (ad+1)%4, bx, by, (bd+1)%4);
		}
		State advance() {
			int nax = ax;
			int nay = ay;
			if(nax != 0 || nay != n-1) {
				if(nax + dx[ad] >= 0 && nax + dx[ad] < n) {
					nax += dx[ad];
				}
				if(nay + dy[ad] >= 0 && nay + dy[ad] < n) {
					nay += dy[ad];
				}
				if(graph[nax][nay] == -1) {
					nax = ax;
					nay = ay;
				}
			}
			int nbx = bx;
			int nby = by;
			if(nbx != 0 || nby != n-1) {
				if(nbx + dx[bd] >= 0 && nbx + dx[bd] < n) {
					nbx += dx[bd];
				}
				if(nby + dy[bd] >= 0 && nby + dy[bd] < n) {
					nby += dy[bd];
				}
				if(graph[nbx][nby] == -1) {
					nbx = bx;
					nby = by;
				}
			}
			return State(nax, nay, ad, nbx, nby, bd);
		}

};

int main(){
    freopen("cownav.in", "r", stdin);
	freopen("cownav.out", "w", stdout);
    cin.tie(0)->sync_with_stdio(0);
    cin >> n;
    for(int i = 0; i < n ;i ++){
        for(int j = 0; j < n;j ++){
            char c;
            cin >> c;
            graph[i][j] = (c == 'H') ? -1 : 1;
        }
    }

    dp[n-1][0][0][n-1][0][1] = 1;
    queue<State> q;
    q.push(State(n-1, 0, 0, n-1, 0, 1));
    while(!q.empty()){
        State cur = q.front();
        q.pop();
        if(cur.ax == 0 && cur.bx == 0 && cur.ay == n-1 && cur.by == n-1){
            cout << dp[cur.ax][cur.ay][cur.ad][cur.bx][cur.by][cur.bd] - 1 << endl;
            break;
        }
        State nxt = cur.turnLeft();
        if(dp[nxt.ax][nxt.ay][nxt.ad][nxt.bx][nxt.by][nxt.bd] == 0) {
                dp[nxt.ax][nxt.ay][nxt.ad][nxt.bx][nxt.by][nxt.bd] = dp[cur.ax][cur.ay][cur.ad][cur.bx][cur.by][cur.bd] + 1;
                q.push(nxt);
        }
        nxt = cur.turnRight();
        if(dp[nxt.ax][nxt.ay][nxt.ad][nxt.bx][nxt.by][nxt.bd] == 0) {
                dp[nxt.ax][nxt.ay][nxt.ad][nxt.bx][nxt.by][nxt.bd] = dp[cur.ax][cur.ay][cur.ad][cur.bx][cur.by][cur.bd] + 1;
                q.push(nxt);
        }
        nxt = cur.advance();
        if(dp[nxt.ax][nxt.ay][nxt.ad][nxt.bx][nxt.by][nxt.bd] == 0) {
                dp[nxt.ax][nxt.ay][nxt.ad][nxt.bx][nxt.by][nxt.bd] = dp[cur.ax][cur.ay][cur.ad][cur.bx][cur.by][cur.bd] + 1;
                q.push(nxt);
        }


    }
}