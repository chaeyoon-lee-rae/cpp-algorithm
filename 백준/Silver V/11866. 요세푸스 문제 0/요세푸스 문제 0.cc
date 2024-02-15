#include <bits/stdc++.h>
using namespace std;  

int N, K;
queue<int> q;
vector<int> v;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> K;
    for (int i=1; i<=N; ++i) {
        q.push(i);
    }
    while (q.size()) {
        int cnt=K-1;
        while (cnt--) {
            q.push(q.front());
            q.pop();
        }
        v.push_back(q.front());
        q.pop();
    }
    cout << "<";
    for (int i=0; i<v.size(); ++i) {
        if (i<v.size()-1) cout << v[i] << ", ";
        else cout << v[i] << '>' << '\n';
    }

    return 0;
}
