#include <bits/stdc++.h>
using namespace std;  

int N; string s;
queue<int> q;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;
    while (N--) {
        cin >> s;
        if (s=="push") {
            int num; cin >> num;
            q.push(num);
        }
        else if (s=="pop") {
            if (q.size()) cout << q.front() << '\n', q.pop();
            else cout << -1 << '\n';
        }
        else if (s=="size") {
            cout << q.size() << '\n';
        }
        else if (s=="empty") {
            cout << (q.empty() ? 1 : 0) << '\n';
        }
        else if (s=="front") {
            cout << (q.size() ? q.front() : -1) << '\n';
        }
        else {
            cout << (q.size() ? q.back() : -1) << '\n';
        }

    }

    return 0;
}
