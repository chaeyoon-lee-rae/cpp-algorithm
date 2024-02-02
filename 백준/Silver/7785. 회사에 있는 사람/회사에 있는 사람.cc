#include <bits/stdc++.h>
using namespace std;  

set<string> st;
int N;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;
    for (int i=0; i<N; ++i) {
        string name, log;
        cin >> name >> log;
        if (log=="enter") st.insert(name);
        else st.erase(name);
    }

    for (auto it=st.rbegin(); it!=st.rend(); ++it) {
        cout << *it << '\n';
    }

    return 0;
}
