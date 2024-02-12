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

    int i=0, j=N-1;
    while (i<j) {
        if (v[i]+v[j]==M) ++ret, ++i, --j;
        else if (v[i]+v[j]>M) --j;
        else ++i;
    }
    cout << ret << '\n';

    return 0;
}
