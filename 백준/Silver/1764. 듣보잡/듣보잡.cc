#include <bits/stdc++.h>
using namespace std;  

int N, M;
set<string> st;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M;
    vector<string> v(N);
    for (int i=0; i<N; ++i) {
        cin >> v[i];
    }
    sort(v.begin(),v.end());
    for (int i=0; i<M; ++i) {
        string temp; cin >> temp;
        if (binary_search(v.begin(), v.end(), temp)) st.insert(temp);
    }

    cout << st.size() << '\n';
    for (auto it:st) cout << it << '\n';

    return 0;
}
