// Floyed-Warshall algorithm
// O(N^3)
// For loop : KIJ

#include "bits/stdc++.h"

using namespace std;

long long arr[501][501];

const long long MAX = 1e18;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m, q;
    cin >> n >> m >> q;

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j ++){
            arr[i][j] = MAX;
            arr[i][i] = 0;

        }
    }

    for(int i = 0; i < m; i++){
        int a, b, c;
        cin >> a >> b >> c;
        arr[a][b] = arr[b][a] = min(arr[a][b], (long long) c);
    }

    for(int k = 1; k <= n ; k ++){
        for(int i = 1; i <= n; i ++){
            for(int j = 1; j <= n; j ++){
                if(arr[i][k] + arr[k][j] < arr[i][j])
                arr[i][j] = arr[j][i] = arr[i][k] + arr[k][j];
            }
        }
    }

    for(int i = 0; i < q; i++){
        int a , b;
        cin >> a >> b;
        // if(a == b) cout << 0 << endl;
        cout << ((arr[a][b] == MAX) ? -1 : arr[a][b]) << endl;
    }
}