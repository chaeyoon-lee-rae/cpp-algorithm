#include <bits/stdc++.h>
using namespace std;  

int N;
string s;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;
    for (int i=0; i<N; ++i) {
        cin >> s;
        cout << s.front() << s.back() << '\n';
    }

    return 0;
}
