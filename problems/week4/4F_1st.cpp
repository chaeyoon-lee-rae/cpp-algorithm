#include <bits/stdc++.h>
using namespace std;  

int N, K, ret, words[51];
bool letter[26];


void combi(int start, int num, int k) {
    if (k==K) {
        int tempRet=0;
        for (int i=0; i<N; ++i) {
            int word = words[i];
            if (!(word & ~num)) ++tempRet;
        }
        ret=max(ret, tempRet);
    }

    for (int i=start+1; i<26; ++i) {
        combi(i, num | (1<<i), k+1);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> K;
    for (int i=0; i<N; ++i) {
        string s; int word=0;
        cin >> s;
        for (char ch:s) word |= (1 << (ch-'a'));
        words[i]=word;
    }

    combi(-1, 0, 0);
    cout << ret << '\n';

    return 0;
}