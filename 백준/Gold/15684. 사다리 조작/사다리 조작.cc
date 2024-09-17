#include <bits/stdc++.h>
using namespace std;  

int a[31][11], n, m, h, ret = -1;
vector<pair<int,int>> emptyLine;

bool go() {
	for (int i=0; i<m-1; ++i) {
		int x = i; int y = 0;
		while(y < n) {
			if (a[y][x]==1) ++x;
			else if (a[y][x]==-1) --x;
			++y;
		}
		if (x!=i) return false;
	}
	return true;
}

void comb(int idx, int cnt, int k) {
	if (cnt==k) {
		if (go())
			ret = k;
		return;
	}

	for (int i=idx+1; i<emptyLine.size(); ++i) {
		int y = emptyLine[i].first;
		int x = emptyLine[i].second;
		if (a[y][x]==0 && a[y][x+1]==0) {
			a[y][x] = 1;
			a[y][x+1] = -1;
			comb(i, cnt+1, k);
			a[y][x] = 0;
			a[y][x+1] = 0;
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	// n = 행, m = 열, h = 주어진 사다리 개수
	cin >> m >> h >> n;

	int x,y;
	for (int i=0; i<h; ++i) {
		cin >> y >> x;
		--y, --x;
		a[y][x] = 1;
		a[y][x+1] = -1;
	}

	for (int i=0; i<n; ++i)
		for (int j=0; j<m-1; ++j) {
			if (a[i][j]==0)
				emptyLine.push_back({i,j});
		}

	for (int cnt=0; cnt<=3; ++cnt) {
		comb(-1, 0, cnt);
		if (~ret) break;
	}

	cout << ret << '\n';

	return 0;
}
