#include <bits/stdc++.h>
using namespace std;  

int a[1001], b[1001], pSumA[2002], pSumB[2002], order, n, m, temp, ret;
map<int,int> mpA, mpB;

void getComb(int n, int pSum[], map<int,int> &mp) {
    for (int i=1; i<=n; ++i) {
        for (int j=0; j<n; ++j) {
            ++mp[pSum[j+i]-pSum[j]];
            if (i==n) break;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> order >> n >> m;
    for (int i=1; i<=n; ++i) {
        cin >> a[i];
        pSumA[i]=pSumA[i-1]+a[i];
    }
    for (int i=1; i<=m; ++i) {
        cin >> b[i];
        pSumB[i]=pSumB[i-1]+b[i];
    }
    for (int i=n+1; i<=n*2; ++i) pSumA[i]=pSumA[i-1]+a[i-n];
    for (int i=m+1; i<=m*2; ++i) pSumB[i]=pSumB[i-1]+b[i-m];
    getComb(n, pSumA, mpA);
    getComb(m, pSumB, mpB);
    ret += mpA[order] + mpB[order];
    for (int i=1; i<order; ++i) {
        ret += (mpA[i]*mpB[order-i]);
    }
    cout << ret << '\n';

    return 0;
}
