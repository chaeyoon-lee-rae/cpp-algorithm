#include <bits/stdc++.h>
using namespace std;  

int h, m, t;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    scanf("%d %d %d", &h, &m, &t);
    h += t/60; m += t%60; 
    h += m/60; h %= 24; m %= 60;
    printf("%d %d\n", h, m);

    return 0;
}