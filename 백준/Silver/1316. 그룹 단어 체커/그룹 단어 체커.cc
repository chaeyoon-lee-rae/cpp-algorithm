#include <bits/stdc++.h>
using namespace std;  

int N, visited[30], cnt;

int checkGroupWord(string s) {
    memset(visited, 0, sizeof(visited));
    visited[s[0]-'a']=1;
    for (int i=1; i<s.size(); ++i) {
        if (visited[s[i]-'a']&&s[i-1]!=s[i]) {
            return 0;
        }
        visited[s[i]-'a']=1;
    }
    return 1;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;
    for (int i=0; i<N; ++i) {
        string s; cin >> s;
        cnt += checkGroupWord(s);
    }
    cout << cnt << '\n';

    return 0;
}