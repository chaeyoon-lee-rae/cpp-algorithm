#include <bits/stdc++.h>
using namespace std;  

char s[101];

bool checkPalin(int l, int r) {
    while(l<=r) {
        if (s[l]!=s[r]) return false;
        ++l, --r;
    }
    return true;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    scanf("%s", s);
    int len=0;
    while(1) {
        if (s[len]==0) break;
        ++len;
    }
    printf("%d\n", checkPalin(0, len-1));

    return 0;
}
