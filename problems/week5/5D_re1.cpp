#include <bits/stdc++.h>
using namespace std;  

int N, temp, r, l;
pair<int,int> a[101];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    scanf("%d", &N);
    for (int i=0; i<N; ++i) {
        int x, y; scanf("%d %d", &x, &y);
        a[i]={x,y};
    }
    sort(a, a+N);
    for (int i=0; i<N; ++i) {
        tie(r, l) = a[i];
        if (temp < r) temp=r;
        temp+=l;
    }
    printf("%d\n", temp);

    return 0;
}
