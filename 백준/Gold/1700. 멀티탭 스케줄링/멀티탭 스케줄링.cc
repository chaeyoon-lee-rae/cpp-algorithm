#include <bits/stdc++.h>
using namespace std;  

const int INF=1e4;
int n, k, a[101], last[101], b[101], ret;
bool plug[101]; 

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    scanf("%d %d", &n, &k);
    for (int i=0; i<k; ++i) {
        scanf("%d", a+i);
        last[a[i]]=i;
    }

    int p=0;
    for (int i=0; i<k; ++i) {
        if (!plug[a[i]]) {
            if (p==n) {
                int idx, mxIdx=0;
                for (int x=0; x<n; ++x) {
                    int here=INF;
                    for (int j=i+1; j<k; ++j) {
                        if (b[x]==a[j]) {
                            here=j; break;
                        }
                    }
                    if (here>mxIdx) {
                        mxIdx=here;
                        idx=x;
                    }
                }
                plug[a[i]]=1;
                plug[b[idx]]=0;
                b[idx]=a[i];
                ++ret;
            } else plug[a[i]]=1, b[p]=a[i], ++p;
        }
    }
    printf("%d\n", ret);

    return 0;
}
