#include <bits/stdc++.h>
using namespace std;  

int a;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> a;
    cout << ((!(a%4)&&(a%100))||!(a%400) ? 1 : 0) << '\n';

    return 0;
}