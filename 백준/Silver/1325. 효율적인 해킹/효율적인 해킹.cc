#include <bits/stdc++.h>
using namespace std;  

int n, m, ret;
vector<int> retV, v[10001];
bool vis[10001];

int dfs(int node) {
	vis[node] = 1;
	int cnt = 1;

	for (int i=0; i<v[node].size(); ++i)
		if (!vis[v[node][i]]) 
			cnt += dfs(v[node][i]);

	return cnt;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> m;

	int x, y;
	for (int i=0; i<m; ++i) {		
		cin >> x >> y;
		v[y].push_back(x);
	}

	for (int i=1; i<=n; ++i) {
		memset(vis, 0, sizeof(vis));

		int temp = dfs(i);
		if (ret < temp) {
			ret = temp;
			retV.clear();
			retV.push_back(i);
		} else if (ret == temp)
			retV.push_back(i);
	}

	for (int val : retV)
		cout << val << " ";

	return 0;
}
