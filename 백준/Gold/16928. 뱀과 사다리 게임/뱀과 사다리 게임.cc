#include <iostream>
#include <unordered_map>
#include <queue>
using namespace std;

queue<int> q;
int vis[101], n, m;
unordered_map<int, int> ladder, snake;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin >> n >> m;
    int x, y;
    for (int i = 0; i < n; ++i) {
        cin >> x >> y;
        ladder[x] = y;
    }
    for (int i = 0; i < m; ++i) {
        cin >> x >> y;
        snake[x] = y;
    }

    q.push(1);
    vis[1] = 1;
    while (q.size()) {
        int x = q.front();
        q.pop();

        for (int i = 1; i <= 6; ++i) {
            int nx = x + i;
            if (snake.find(nx) != snake.end()) {
                nx = snake[nx];
            }
            else if (ladder.find(nx) != ladder.end())
                nx = ladder[nx];

            if (nx > 100 || vis[nx]) continue;
            q.push(nx);
            vis[nx] = vis[x] + 1;
        }
    }

    cout << vis[100] - 1 << "\n";

    return 0;
}
