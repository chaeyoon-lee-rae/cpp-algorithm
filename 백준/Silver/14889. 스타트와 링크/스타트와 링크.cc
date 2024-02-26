#include <bits/stdc++.h>
using namespace std;  

const int INF=1e9;
int N, ret=INF, s[21][21];
vector<int> v;
bool vis[21];

int go(vector<int> &a, vector<int> &b) {
    int score1=0, score2=0;
    for (int i=0; i<a.size()-1; ++i) {
        for (int j=i+1; j<a.size(); ++j) {
            score1 += s[a[i]][a[j]] + s[a[j]][a[i]];
            score2 += s[b[i]][b[j]] + s[b[j]][b[i]];
        }
    }
    return abs(score1 - score2);
}

void combi(int start, int cnt) {
    if (cnt==N/2) {
        vector<int> v1, v2;
        for (int i=0; i<N; ++i) {
            if (vis[i]) v1.push_back(i);
            else v2.push_back(i);
        }
        ret = min(ret, go(v1, v2));
        return;
    }
    for (int i=start+1; i<N; ++i) {
        vis[i]=1;
        combi(i, cnt+1);
        vis[i]=0;
    }
    return;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;
    for (int i=0; i<N; ++i) {
        for (int j=0; j<N; ++j) {
            cin >> s[i][j];
        }
    }

    combi(-1, 0);
    cout << ret << '\n';

    return 0;
}
