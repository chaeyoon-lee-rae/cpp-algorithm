#include <bits/stdc++.h>
using namespace std;  

string s;
int dp[2501][2501], dp2[2501];
const int INF=1e6;

int go(int idx) {
    if (idx==s.size()) return 0;
    int &ret=dp2[idx];
    if(ret!=INF) return ret;
    for (int i=1; i+idx<=s.size(); ++i) {
        if(dp[idx][i]) ret=min(ret,go(idx+i)+1);
    }
    return ret;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> s;
    for (int i=0; i<s.size(); ++i) {
        dp[i][1]=1;
    }
    for (int i=0; i<s.size()-1; ++i) {
        if(s[i]==s[i+1]) dp[i][2]=1;
    }
    for (int len=3; len<=s.size(); ++len) {
        for (int i=0; i+len<=s.size(); ++i) {
            if (s[i]==s[i+len-1]&&dp[i+1][len-2]) {
                dp[i][len]=1;
            }
        }
    }

    fill(dp2, dp2+2501, INF);
    cout << go(0) << '\n';

    return 0;
}
