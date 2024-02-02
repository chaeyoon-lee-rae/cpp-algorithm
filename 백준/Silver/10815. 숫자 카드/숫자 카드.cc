#include <bits/stdc++.h>
using namespace std;  

int N, M;
vector<int> v;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;
    for (int i=0; i<N; ++i) {
        int temp; cin >> temp;
        v.push_back(temp);
    }
    sort(v.begin(), v.end());

    cin >> M;
    for (int i=0; i<M; ++i) {
        int temp; cin >> temp;
        cout << (binary_search(v.begin(), v.end(), temp) ? 1 : 0) << ' ';
    }

    return 0;
}
