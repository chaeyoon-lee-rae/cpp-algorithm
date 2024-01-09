#include <bits/stdc++.h>
using namespace std;  

string s;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> s;
    s += '?'; s += '?'; s += '!';
    cout << s << '\n';

    return 0;
}