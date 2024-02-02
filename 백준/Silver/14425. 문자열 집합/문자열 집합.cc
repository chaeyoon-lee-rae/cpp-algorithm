#include <bits/stdc++.h>
using namespace std;  

int N, M, cnt;
vector<string> v;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M;
    for (int i=0; i<N; ++i) {
        string temp; cin >> temp;
        v.push_back(temp);
    }
    sort(v.begin(),v.end());

    for (int i=0; i<M; ++i) {
        string temp; cin >> temp;
        if (binary_search(v.begin(), v.end(), temp)) ++cnt;
    }
    cout << cnt << '\n';

    return 0;
}
