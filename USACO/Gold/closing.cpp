#include <bits/stdc++.h>

using namespace std;
int uf[200001];
int n, m;
int cnt[200001];
vector<int> adj[200001];
bool open[200001];

int find(int a){
	if(uf[a] != a){
		uf[a] = find(uf[a]);
	}
	return uf[a];
}

void unite(int a, int b){
	a = find(a);
	b = find(b);
	if(rand() %2){ 
		uf[a] = b;
		cnt[b] += cnt[a];
	}else{ 
		uf[b] = a;
		cnt[a] += cnt[b];
	}
}

int main(){
	freopen("closing.in", "r", stdin);
	freopen("closing.out", "w", stdout);
	cin >> n >> m;
	for(int i = 0; i < m; i++){
		int a , b;
		cin >> a >> b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	for(int i = 0; i <= n; i++) {
		uf[i] = i;
		cnt[i] = 1;
	}

	vector<int> in(n);
	for(int i = 0; i < n; i++){
		cin >> in[i];
	}
	reverse(in.begin(), in.end());
	
	vector<string> ans(n);
	for(int num = 0; num < n; num ++){
		int a = in[num];
		open[a] = true;
		for(auto i : adj[a]){
			if(find(a) != find(i) && open[i]){
				unite(a, i);
			}
		}
		if(cnt[find(a)] == num+1) ans[num] = "YES";
		else ans[num] = "NO";
	}
	reverse(ans.begin(), ans.end());
	for(auto a : ans)
		cout << a << endl;
}


