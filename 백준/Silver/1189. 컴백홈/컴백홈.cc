#include <bits/stdc++.h>
using namespace std;  

int r, c, k, dy[]={0,1,0,-1}, dx[]={1,0,-1,0}, vis[6][6], ret;
char a[6][6];

void go(int y, int x) {
	if (y==r-1 && x==c-1 && vis[y][x]==k) {
		++ret;
		return;
	}

	for (int i=0; i<4; ++i) {
		int ny = y + dy[i];
		int nx = x + dx[i];
		if (ny<0||nx<0||ny>=r||nx>=c) continue;
		if (vis[ny][nx]||a[ny][nx]=='T') continue;
		vis[ny][nx]=vis[y][x]+1;
		go(ny,nx);
		vis[ny][nx]=0;
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> r >> c >> k;
	for (int i=0; i<r; ++i)
		for (int j=0; j<c; ++j)
			cin >> a[r-i-1][j];

	if (a[0][0]=='T'||a[r-1][c-1]=='T') {
		cout << 0 << '\n';
		return 0;
	}

	vis[0][0]=1;
	go(0,0);
	cout << ret << '\n';

	return 0;
}
