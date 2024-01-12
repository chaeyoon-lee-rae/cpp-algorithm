#include <bits/stdc++.h>
using namespace std;  

int N, R;
char ch[21];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    scanf("%d", &N);
    for (int i=0; i<N; ++i) {
        scanf("%d %s", &R, ch);
        for (int j=0; j<strlen(ch); ++j) {
            for (int k=0; k<R; ++k) printf("%c",ch[j]);
        }
        printf("\n");
    }
    

    return 0;
}
