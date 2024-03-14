#include <bits/stdc++.h>
using namespace std;  

int n, k, words[51];

int comb(int idx, int cnt, int mask) {
    if (cnt < 0) return 0;
    if (idx==26) {
        int tempRet=0;
        for (int i=0; i<n; ++i) {
            if ((words[i] & mask)==words[i]) ++tempRet;
        }
        return tempRet;
    }
    int ret = comb(idx+1, cnt-1, mask|(1<<idx));
    if (idx!='a'-'a'&&idx!='n'-'a'&&idx!='t'-'a'&&idx!='i'-'a'&&idx!='c'-'a') {
        ret = max(ret, comb(idx+1, cnt, mask));
    }
    return ret;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> k;
    for (int i=0; i<n; ++i) {
        string s; cin >> s;
        for (char ch:s) {
            words[i] |= (1<<(ch-'a'));
        }
    }
    cout << comb(0,k,0) << '\n';

    return 0;
}
