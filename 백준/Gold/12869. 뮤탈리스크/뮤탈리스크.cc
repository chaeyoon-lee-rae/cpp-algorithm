#include <bits/stdc++.h>
using namespace std;  

struct health { int a, b, c; };
queue<health> q;
int n, a[3], vis[61][61][61];
int attk[6][3] = {{9,3,1},{9,1,3},{3,9,1},{3,1,9},{1,3,9},{1,9,3}};


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;
	for (int i=0; i<n; ++i)
		cin >> a[i];
	
	q.push({a[0], a[1], a[2]});
	vis[a[0]][a[1]][a[2]] = 1;

	while(q.size()) {
		if (vis[0][0][0]) break;

		health h = q.front();
		q.pop();
		//cout << "{" << h.a << " " << h.b << " " << h.c << "}" << '\n';

		for (int i=0; i<6; ++i) {
			int na = max(h.a - attk[i][0], 0);
			int nb = max(h.b - attk[i][1], 0);
			int nc = max(h.c - attk[i][2], 0);

			if (!vis[na][nb][nc]) {
				vis[na][nb][nc] = vis[h.a][h.b][h.c] + 1;
				q.push({na, nb, nc});
			}
		}
	}

	cout << vis[0][0][0] - 1 << '\n';

	return 0;
}
