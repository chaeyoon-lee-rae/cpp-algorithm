#include <bits/stdc++.h>
using namespace std;  

int N;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;
    int r = pow(2,N)+1;
    cout << r*r << '\n';

    return 0;
}