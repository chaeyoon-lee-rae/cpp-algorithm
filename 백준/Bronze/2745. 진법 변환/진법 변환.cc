#include <bits/stdc++.h>
using namespace std;  

int nota, ret;
string s;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> s >> nota;
    for (int i=0; i<s.size(); ++i) {
        int num=0;
        if (s[i]>=65) num=s[i]-'A'+10;
        else num=s[i]-'0';
        ret += num * pow(nota, s.size()-i-1);
    }
    cout << ret << '\n';

    return 0;
}
