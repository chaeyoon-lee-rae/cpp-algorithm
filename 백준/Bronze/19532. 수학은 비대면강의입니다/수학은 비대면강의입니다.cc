#include <bits/stdc++.h>
using namespace std;  

int a, b, c, d, e, f, retx, rety;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    scanf("%d %d %d %d %d %d", &a, &b, &c, &d, &e, &f);
    for (int x=-999; x<=999; ++x) {
        for (int y=-999; y<=999; ++y) {
            if (a*x + b*y == c && d*x + e*y == f) retx = x, rety = y;
        }
    } 
    printf("%d %d\n", retx, rety);

    return 0;
}
