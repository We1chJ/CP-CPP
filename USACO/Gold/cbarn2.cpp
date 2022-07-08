#include <bits/stdc++.h>
using namespace std;
#define int long long
const int LINF = 1e15;
int a[100010], dp[101][8][101], mn[101][8], ans = LINF;
int32_t main()
{
	ifstream cin("cbarn2.in");
	ofstream cout("cbarn2.out");
	int n, k; cin >> n >> k;
	for(int i = 0; i < n; i++) cin >> a[i];
	for(int _ = 0; _ < n; _++)
	{
		rotate(a, a+1, a+n);
		for(int i = 0; i <= n; i++)
			for(int j = 0; j <= 7; j++)
				for(int l = 0; l <= n; l++)
					dp[i][j][l] = mn[i][j] = LINF;
		dp[1][1][0] = mn[1][1] = 0;
		for(int i = 2; i <= n; i++){
			for(int j = 1; j <= 7; j++){
				for(int l = 0; l <= i; l++){
					if(l) dp[i][j][l] = dp[i-1][j][l-1]+l*a[i-1];
					else dp[i][j][l] = min(dp[i][j][l], mn[i-1][j-1]);
					mn[i][j] = min(mn[i][j], dp[i][j][l]);
				}
			}
		}
        ans = min(ans, mn[n][min(n,k)]);
	}
	cout << ans << '\n';
}
