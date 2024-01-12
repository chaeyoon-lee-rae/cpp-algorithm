#include <bits/stdc++.h>
using namespace std;  

string s;
int N;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> s >> N;
    cout << s[--N] << '\n';

    return 0;
}