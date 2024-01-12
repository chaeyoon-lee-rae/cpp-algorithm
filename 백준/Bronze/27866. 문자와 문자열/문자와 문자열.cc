#include <bits/stdc++.h>
using namespace std;  

char c[1004];
int N;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    scanf("%s %d", c, &N);
    printf("%c\n", c[--N]);

    return 0;
}
