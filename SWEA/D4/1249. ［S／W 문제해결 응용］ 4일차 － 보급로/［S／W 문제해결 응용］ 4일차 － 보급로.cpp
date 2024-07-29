#include<iostream>
#include<queue>
#include<tuple>
#include<string>
using namespace std;

typedef pair<int, int> pii;
const int INF = 1e9;
int min_path[101][101], n, a[101][101], dy[] = { 0,1,0,-1 }, dx[] = { 1,0,-1,0 };
string s;
struct cmp {
	bool operator() (pii a, pii b) {
		return min_path[a.first][a.second] > min_path[b.first][b.second];
	}
};
priority_queue<pii, vector<pii>, cmp> pq;


//void printa() {
//	for (int i = 0; i < n; ++i) {
//		for (int j = 0; j < n; ++j)
//			cout << a[i][j] << " ";
//		cout << "\n";
//	}
//	cout << "\n";
//}
//
//void printMin() {
//	for (int i = 0; i < n; ++i) {
//		for (int j = 0; j < n; ++j)
//			cout << (min_path[i][j] == INF ? "-" : to_string(min_path[i][j])) << " ";
//		cout << "\n";
//	}
//	cout << "\n";
//}

int main(int argc, char** argv)
{
	int test_case;
	int T;

	//freopen("sample_input.txt", "r", stdin);
	cin >> T;

	for (test_case = 1; test_case <= T; ++test_case)
	{
		int y, x;

		cin >> n;
		for (int i = 0; i < n; ++i) {
			cin >> s;
			for (int j = 0; j < n; ++j)
				a[i][j] = s[j] - '0';
		}

		fill(&min_path[0][0], &min_path[0][0] + 101 * 101, INF);

		//printa();

		min_path[0][0] = 0;
		pq.push({ 0,0 });
		while (pq.size()) {
			tie(y, x) = pq.top();
			pq.pop();

			//cout << "{" << y << ", " << x << "}\n";

			for (int i = 0; i < 4; ++i) {
				int ny = y + dy[i];
				int nx = x + dx[i];

				if (ny < 0 || nx < 0 || ny >= n || nx >= n) 
					continue;
				if (min_path[ny][nx] > min_path[y][x] + a[ny][nx]) {
					min_path[ny][nx] = min_path[y][x] + a[ny][nx];
					pq.push({ ny,nx });
				}
			}

			//printMin();
			if (min_path[n - 1][n - 1] != INF) break;
		}

		cout << "#" << test_case << " ";
		cout << min_path[n - 1][n - 1] << "\n";

	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}

