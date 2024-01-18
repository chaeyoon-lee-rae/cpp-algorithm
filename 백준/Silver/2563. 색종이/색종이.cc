#include <bits/stdc++.h>
using namespace std;  

int N, x, y, cnt;
bool a[101][101];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;
    for (int i=0; i<N; ++i) {
        cin >> x >> y;
        for (int i=y; i<y+10; ++i) {
            for (int j=x; j<x+10; ++j) {
                a[i][j] = 1;
            }
        }
    }

    for (int i=0; i<=100; ++i) {
        for (int j=0; j<=100; ++j) {
            if (a[i][j]) ++cnt;
        }
    }
    cout << cnt << '\n';

    return 0;
}