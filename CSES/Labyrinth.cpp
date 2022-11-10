#include "bits/stdc++.h"
using namespace std;
bool visited[1001][1001];
char input[1001][1001];

int dir[1001][1001];

// up down left right
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};
string REF = "UDLR";

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int n, m;
    cin >> n >> m;

    pair<int, int> A, B;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            cin >> input[i][j];
            if(input[i][j] == 'A') A = make_pair(i, j);
            if(input[i][j] == 'B') B = make_pair(i, j);
        }
    }

    queue<pair<int, int>> q;
    q.push(A); 
    visited[A.first][A.second] = true; 

    while(!q.empty()){
        pair<int, int> p = q.front();
        q.pop();

        for(int i = 0; i < 4; i++){
            int ix = p.first + dx[i];
            int iy = p.second + dy[i];
            if(ix < 1 || ix > n || iy < 1 || iy > m) continue;
            if(input[ix][iy] == '#') continue;
            if(visited[ix][iy]) continue;
            visited[ix][iy] = true;
            q.push(make_pair(ix, iy));
            dir[ix][iy] = i;
        }
    }

    if(!visited[B.first][B.second])
        cout << "NO" << endl;
    else{
        cout << "YES" << endl;
        int curx = B.first, cury = B.second;
        vector<int> v;
        while(curx != A.first || cury != A.second){
            v.push_back(dir[curx][cury]);
            int c = dir[curx][cury];
            curx -= dx[c];
            cury -= dy[c];
        }
        reverse(v.begin(), v.end());
        cout << v.size() << endl;
        for(auto a : v)
            cout << REF[a];
        cout << endl;
    }
}