#include <bits/stdc++.h>
using namespace std;  

string s;
int t;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> s;
    for (int i=0; i<s.size(); ++i) {
        if ((s[i]-'A') < 3) t+=3;
        else if ((s[i]-'A') < 6) t+=4;
        else if ((s[i]-'A') < 9) t+=5;
        else if ((s[i]-'A') < 12) t+=6;
        else if ((s[i]-'A') < 15) t+=7;
        else if ((s[i]-'A') < 19) t+=8;
        else if ((s[i]-'A') < 22) t+=9;
        else t+=10;
    }
    cout << t << '\n';

    return 0;
}
