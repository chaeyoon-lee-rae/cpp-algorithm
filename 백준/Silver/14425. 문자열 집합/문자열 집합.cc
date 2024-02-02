#include <bits/stdc++.h>
using namespace std;  

set<string> st;
int N, M, cnt;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M;
    for (int i=0; i<N; ++i) {
        string temp; cin >> temp;
        st.insert(temp);
    }
    for (int i=0; i<M; ++i) {
        string temp; cin >> temp;
        if (st.find(temp)!=st.end()) ++cnt;
    }
    cout << cnt << '\n';
    
    return 0;
}
