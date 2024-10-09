#include <iostream>
#include <algorithm>
using namespace std;

int n, m, l, k, ret;
pair<int, int> star[101];

bool check(int startY, int startX, int curY, int curX) {
    return startY <= curY && curY <= startY + l && startX <= curX && curX <= startX + l;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> m >> n >> l >> k;
    for (int i = 0; i < k; ++i)
        cin >> star[i].second >> star[i].first;

    for (int i = 0; i < k; ++i) {
        int x = star[i].second;
        for (int j = 0; j < k; ++j) {
            int y = star[j].first;
            int cnt = 0;
            for (int p = 0; p < k; ++p) {
                int curY = star[p].first;
                int curX = star[p].second;
                if (check(y, x, curY, curX))
                    ++cnt;
            }
            ret = max(ret, cnt);
        }
    }

    cout << k - ret << "\n";

    return 0;
}
