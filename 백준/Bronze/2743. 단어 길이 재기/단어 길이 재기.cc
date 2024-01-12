#include <bits/stdc++.h>
using namespace std;  

char c[104];
int cnt;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    scanf("%s", c);
    int i=0; while(c[i]!='\0') ++cnt, ++i;
    printf("%d\n", cnt);

    return 0;
}
