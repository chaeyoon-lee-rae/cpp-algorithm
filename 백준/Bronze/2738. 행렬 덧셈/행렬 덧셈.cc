#include <bits/stdc++.h>
using namespace std;  

int a[101][101], N, M;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M;
    int k=2;
    while (k--) {
        for (int i=0; i<N; ++i) {
            for (int j=0; j<M; ++j) {
                int num; cin >> num;
                a[i][j]+=num;
            }
        }
    }

    for (int i=0; i<N; ++i) {
        for (int j=0; j<M; ++j) {
            cout << a[i][j] << ' ';
        }
        cout << '\n';
    }

    return 0;
}