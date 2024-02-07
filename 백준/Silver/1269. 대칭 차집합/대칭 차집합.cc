#include <bits/stdc++.h>
using namespace std;  

int N, M;
set<int> st;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M;
    for (int i=0; i<N; ++i) {
        int temp; cin >> temp;
        st.insert(temp);
    }
    for (int i=0; i<M; ++i) {
        int temp; cin >> temp;
        if (st.find(temp)!=st.end()) st.erase(temp);
        else st.insert(temp);
    }
    cout << st.size() << '\n';

    return 0;
}
