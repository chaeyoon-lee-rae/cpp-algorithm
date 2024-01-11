#include <bits/stdc++.h>
using namespace std;  

int N, temp, num, a[201];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;
    for (int i=0; i<N; ++i) {
        cin >> temp;
        a[temp+100] += 1;
    }
    cin >> num;
    cout << a[num+100] << '\n';

    return 0;
}