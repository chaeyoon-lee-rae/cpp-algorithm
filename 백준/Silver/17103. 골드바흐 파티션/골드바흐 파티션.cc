#include <bits/stdc++.h>
using namespace std;  

const int mx=1000001;
int N, num, cnt; bool a[mx];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    for (int i=0; i*i<mx; ++i) {
        if (i<=1) a[i]=true;
        if (!a[i]) {
            for (int j=i*i; j<=mx; j+=i) {
                a[j]=true;
            }
        }
    }

    cin >> N;
    for (int i=0; i<N; ++i) {
        cin >> num;
        cnt=0;
        for (int j=2; j<=num/2; ++j) {
            if (!a[j]&&!a[num-j]) ++cnt;
        }
        cout << cnt << '\n';
    }

    return 0;
}
