#include <bits/stdc++.h>
using namespace std;  

const int INF = 1e9;
int fireVis[1001][1001], jVis[1001][1001], dy[]={0,1,0,-1}, dx[]={1,0,-1,0}, n, m;
bool a[1001][1001];
queue<pair<int,int>> qF, qJ;

void fireBfs() {
	int y, x;
	while(qF.size()) {
		tie(y,x) = qF.front();
		qF.pop();

		for (int i=0; i<4; ++i) {
			int ny = y + dy[i];
			int nx = x + dx[i];
			if (ny<0||nx<0||ny>=n||nx>=m||fireVis[ny][nx]!=INF) continue;
			if (a[ny][nx]) {
				fireVis[ny][nx] = fireVis[y][x] + 1;
				qF.push({ny,nx});
			}
		}
	}
}

int jBfs() {
	int y, x;
	while(qJ.size()) {
		tie(y,x) = qJ.front();
		qJ.pop();
		if (y==0||x==0||y==n-1||x==m-1)
			return jVis[y][x];

		for (int i=0; i<4; ++i) {
			int ny = y + dy[i];
			int nx = x + dx[i];
			if (jVis[ny][nx] || fireVis[ny][nx]<=jVis[y][x]+1) continue;
			if (a[ny][nx]) {
				jVis[ny][nx] = jVis[y][x] + 1;
				qJ.push({ny,nx});
			}
		}
	}

	return -1;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	fill(&fireVis[0][0], &fireVis[0][0]+1001*1001, INF);

	string s;
	cin >> n >> m;
	for (int i=0; i<n; ++i) {
		cin >> s;
		for (int j=0; j<m; ++j) {
			if (s[j]!='#') a[i][j]=1;
			if (s[j]=='F') qF.push({i, j}), fireVis[i][j]=1;
			if (s[j]=='J') qJ.push({i, j}), jVis[i][j]=1;
		}
	}

	fireBfs();
	int ret = jBfs();
	if (~ret) cout << ret << '\n';
	else cout << "IMPOSSIBLE" << "\n";

	return 0;
}
