#include <bits/stdc++.h>
using namespace std;  

int N;
char s[1001];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    scanf("%d", &N);
    for (int i=0; i<N; ++i) {
        scanf("%s", s);
        printf("%c%c\n", s[0], s[strlen(s)-1]);
    }

    return 0;
}
