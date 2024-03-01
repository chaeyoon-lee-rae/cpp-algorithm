#include <bits/stdc++.h>
using namespace std;  

int n, m, t, x, d, k, ret;
bool zero[51][51];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    scanf("%d %d %d", &n ,&m, &t);
    vector<vector<int>> v(n, vector<int>(m,0));
    for (int i=0; i<n; ++i) {
        for (int j=0; j<m; ++j) {
            int temp; scanf("%d", &temp);
            v[i][j]=temp;
        }
    }
    while (t--) {
        memset(zero, 0, sizeof(zero));
        scanf("%d %d %d", &x, &d, &k);
        for (int i=x; i<=n; i+=x) {
            int idx = i-1;
            if (d) rotate(v[idx].begin(), v[idx].begin()+k, v[idx].end());
            else rotate(v[idx].rbegin(), v[idx].rbegin()+k, v[idx].rend());
        }
        int sum=0; bool flag2=0; int cnt=0;
        for (int i=0; i<n; ++i) {
            for (int j=0; j<m; ++j) {
                if (v[i][j]==0) continue;
                bool flag=0;
                if (i<n-1 && v[i][j]==v[i+1][j]) zero[i+1][j]=1, flag=1;
                if (j==m-1 && v[i][j]==v[i][0]) zero[i][0]=1, flag=1;
                else if (j<m-1 && v[i][j]==v[i][j+1]) zero[i][j+1]=1, flag=1;
                if (flag) zero[i][j]=1, flag2=1;
                sum+=v[i][j]; ++cnt;
            }
        }
        if (!flag2) {
            float avg = (float)sum / (float)cnt;
            for (int i=0; i<n; ++i) {
                for (int j=0; j<m; ++j) {
                    if (v[i][j]) {
                        if (v[i][j]<avg) ++v[i][j];
                        else if (v[i][j]>avg) --v[i][j];
                    }
                }
            }
        }
        else {
            for (int i=0; i<n; ++i) {
                for (int j=0; j<m; ++j) {
                    if (zero[i][j]) v[i][j]=0;
                }
            }
        }
    }

    for (int i=0; i<n; ++i) {
        for (int j=0; j<m; ++j) {
            ret += v[i][j];
        }
    }
    printf("%d\n", ret);

    return 0;
}
