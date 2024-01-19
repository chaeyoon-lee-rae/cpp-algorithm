#include <bits/stdc++.h>
using namespace std;  

int N, M;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M;
    while (N!=0&&M!=0) {
        if (M/N && M%N==0) cout << "factor" << '\n';
        else if (N/M && N%M==0) cout << "multiple" << '\n';
        else cout << "neither" << '\n';
        cin >> N >> M;
    }

    return 0;
}