#include <bits/stdc++.h>
using namespace std;  

const int INF = 1e9;
int a[11][11], n, dy[]={0,1,0,-1}, dx[]={1,0,-1,0}, sz, ret=INF;
bool vis[11][11];

bool check(int y, int x) {
	for (int i=0; i<4; ++i) {
		int ny = y + dy[i];
		int nx = x + dx[i];
		if (ny<0||nx<0||ny>=n||nx>=n) return false;
		if (vis[ny][nx]) return false;
	}
	return true;
}

int change(int y, int x, bool flag) {
	int sum = a[y][x];
	vis[y][x]=flag;
	for (int i=0; i<4; ++i) {
		int ny = y + dy[i];
		int nx = x + dx[i];
		sum+=a[ny][nx];
		vis[ny][nx]=flag;
	}
	return sum;
}

void comb(int idx, int cnt, int price) {
	if (cnt==3) {
		ret = min(ret,price);
		return;
	}

	for (int i=idx+1; i<sz; ++i) {
		int y = i/n;
		int x = i%n;
		if (check(y,x)) {
			int sum = change(y,x,1);
			comb(i,cnt+1,price+sum);
			change(y,x,0);
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;
	for (int i=0; i<n; ++i)
		for (int j=0; j<n; ++j)
			cin >> a[i][j];

	sz = n*n;
	comb(-1, 0, 0);
	cout << ret << '\n';

	return 0;
}
