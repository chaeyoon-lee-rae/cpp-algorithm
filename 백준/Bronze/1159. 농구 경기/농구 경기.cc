#include <bits/stdc++.h>
using namespace std;  

int n;
char ret[30], s[31];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    scanf("%d", &n);
    for (int i=0; i<n; ++i) {
        scanf("%s", s);
        ++ret[s[0]-'a'];
    }

    int cnt=0;
    for (char i='a'; i<='z'; ++i) {
        if (ret[i-'a']>=5) {
            printf("%c", i);
            ++cnt;
        }
    }
    if (cnt==0) printf("PREDAJA\n");

    return 0;
}
