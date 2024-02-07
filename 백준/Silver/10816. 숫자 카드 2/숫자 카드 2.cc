#include <bits/stdc++.h>
using namespace std;  

int N, M;
unordered_map<int, int> mp;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;
    for (int i=0; i<N; ++i) {
        int temp; cin >> temp;
        ++mp[temp];
    }
    cin >> M;
    for (int i=0; i<M; ++i) {
        int temp; cin >> temp;
        cout << mp[temp] << ' ';
    }

    return 0;
}
