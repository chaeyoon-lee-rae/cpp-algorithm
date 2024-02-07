#include <bits/stdc++.h>
using namespace std;  

int N, M, ret;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M;
    vector<int> v(N);
    for (int i=0; i<N; ++i) {
        cin >> v[i];
    }
    sort(v.begin(), v.end());
    for (int i=0; i<M; ++i) {
        int temp; cin >> temp;
        if (binary_search(v.begin(), v.end(), temp)) ++ret;
    }
    cout << N + M - ret * 2 << '\n';

    return 0;
}
