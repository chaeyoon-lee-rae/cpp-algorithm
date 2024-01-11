#include <bits/stdc++.h>
using namespace std;  

int N, M, temp1, temp2, temp3, a[101];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M;
    for (int i=0; i<M; ++i) {
        cin >> temp1 >> temp2 >> temp3;
        for (int j=temp1; j<=temp2; ++j) {
            a[j]=temp3;
        }
    }
    
    for (int i=1; i<=N; ++i) cout << a[i] << " ";

    return 0;
}