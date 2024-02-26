#include <bits/stdc++.h>
using namespace std;  

const int INF = 1e9;
int N, s[21][21], ret=INF;

int calc(vector<int> v) {
    int score=0;
    for (int i=0; i<v.size()-1; ++i) {
        for (int j=i+1; j<v.size(); ++j) {
            score+=s[v[i]][v[j]];
            score+=s[v[j]][v[i]];
        }
    }
    return score;
}

void go(int num) {
    vector<int> v1, v2;
    for (int i=0; i<N; ++i) {
        if ((1<<i)&num) v1.push_back(i);
        else v2.push_back(i);
    }
    ret = min(ret, abs(calc(v1) - calc(v2)));
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
    for (int i=0; i<(1<<N); ++i) {
        int cnt = 0;
        for (int j=0; j<N; ++j) {
            if ((1<<j)&i) ++cnt;
        }
        if (cnt==N/2) go(i);
    }
    cout << ret << '\n';

    return 0;
}
