#include <bits/stdc++.h>
using namespace std;  

string s, sub;
int cnt;

bool compLetters(string sub) {
    return sub=="c="||sub=="c-"||sub=="d-"||sub=="lj"||sub=="nj"||sub=="s="||sub=="z=";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> s;
    for (int i=0; i<s.size(); ++i) {
        if (i+2<s.size()&&s.substr(i,3)=="dz=") ++cnt, i+=2;
        else if (i+1<s.size()&&compLetters(s.substr(i,2))) ++cnt, ++i;
        else ++cnt;
    }
    cout << cnt << '\n';

    return 0;
}
