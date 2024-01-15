#include <bits/stdc++.h>
using namespace std;  

int N, x, i, j, ret;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;
    vector<int> v(N);
    for (int i=0; i<N; ++i) {
        cin >> v[i];
    }
    cin >> x;
    sort(v.begin(), v.end());

    j=N-1;
    while (i<j) {
        if (v[i]+v[j]==x) ++ret, ++i, --j;
        else if (v[i]+v[j]<x) ++i;
        else --j;
    }

    cout << ret << '\n';

    return 0;
}