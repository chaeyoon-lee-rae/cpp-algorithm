#include <bits/stdc++.h>
using namespace std;  

const int INF = 1e7;
int N, temp, ret_min=INF, ret_max=-INF;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;
    for (int i=0; i<N; ++i) {
        cin >> temp;
        ret_min = min(ret_min, temp);
        ret_max = max(ret_max, temp);
    }

    cout << ret_min << " " << ret_max << '\n';

    return 0;
}