#include <bits/stdc++.h>
using namespace std;  

char s1[4], s2[4];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    scanf("%s %s", s1, s2);
    reverse(s1, s1+3);
    reverse(s2, s2+3);
    printf("%s\n", (strcmp(s1,s2)>0 ? s1 : s2));

    return 0;
}
