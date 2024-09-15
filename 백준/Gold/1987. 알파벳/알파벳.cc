#include <bits/stdc++.h>
using namespace std;  

int r, c, ret, dy[]={0,1,0,-1}, dx[]={1,0,-1,0};
char a[21][21];
bool visChar[27], visited[21][21];

void dfs(int y, int x, int cnt) {
	ret = max(ret, cnt);
	for (int i=0; i<4; ++i) {
		int ny = y + dy[i];
		int nx = x + dx[i];
		if (ny<0||nx<0||ny>=r||nx>=c) continue;
		if (visited[ny][nx]||visChar[a[ny][nx]-'A']) continue;
		visited[ny][nx] = 1;
		visChar[a[ny][nx]-'A'] = 1;
		dfs(ny,nx,cnt+1);
		visited[ny][nx] = 0;
		visChar[a[ny][nx]-'A'] = 0;
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> r >> c;
	string s;
	for (int i=0; i<r; ++i) {
		cin >> s;
		for (int j=0; j<c; ++j) {
			a[i][j] = s[j];
		}
	}

	visited[0][0]=1;
	visChar[a[0][0]-'A']=1;
	dfs(0,0,1);
	cout << ret << '\n';

	return 0;
}
