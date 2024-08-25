#include <bits/stdc++.h>
using namespace std;  

int n, m, dy[]={0,1,0,-1}, dx[]={1,0,-1,0};
bool a[101][101], a_cpy[101][101], visited[101][101];

void dfs(int y, int x) {
    visited[y][x] = 1;

    for (int i=0; i<4; ++i) {   
        int ny = y + dy[i];
        int nx = x + dx[i];

        if (ny<0||nx<0||ny>=n||nx>=m||visited[ny][nx]) continue;
        if (a[ny][nx]) {
            visited[ny][nx]=1;
            a[ny][nx] = 0;
        } else 
            dfs(ny, nx);
    }
}

int cntChz(int y, int x) {
	int cnt = 1;
    visited[y][x] = 1;

    for (int i=0; i<4; ++i) {   
        int ny = y + dy[i];
        int nx = x + dx[i];

        if (ny<0||nx<0||ny>=n||nx>=m||visited[ny][nx]) continue;
        if (a_cpy[ny][nx]) 
			cnt += cntChz(ny, nx);
    }

	return cnt;
}

bool checkEmpty() {
    for (int i=0; i<n; ++i)
        for (int j=0; j<m; ++j)
            if (a[i][j])
                return false;
    return true;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m;
    for (int i=0; i<n; ++i)
        for (int j=0; j<m; ++j)
            cin >> a[i][j];

    int cnt, t = 0;
    while (true) {
        if (checkEmpty()) break;
        memset(visited, 0, sizeof(visited));
		memcpy(a_cpy, a, sizeof(a));

		memset(visited, 0, sizeof(visited));
        dfs(0,0);
        ++t;
    }

	memset(visited, 0, sizeof(visited));
	cnt = 0;
	for (int i=0; i<n; ++i)
		for (int j=0; j<m; ++j)
			if (a_cpy[i][j] && !visited[i][j])            
				cnt += cntChz(i, j);

    cout << t << "\n";
    cout << cnt << '\n';

    return 0;
}
