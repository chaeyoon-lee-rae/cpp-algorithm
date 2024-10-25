#include <iostream>
using namespace std;

int n, a[2001], m, s, e;
bool dp[2001][2001];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        dp[i][i] = 1;
    }

    for (int i = 0; i < n - 1; ++i) {
        if (a[i] == a[i + 1])
            dp[i][i + 1] = 1;
    }
    for (int len = 2; len < n; ++len)
        for (int i = 0; i + len < n; ++i)
            if (a[i] == a[i + len])
                dp[i][i + len] = dp[i + 1][i + len - 1];

    cin >> m;
    while (m--) {
        cin >> s >> e;
        --s, --e;
        cout << dp[s][e] << "\n";
    }


    return 0;
}
