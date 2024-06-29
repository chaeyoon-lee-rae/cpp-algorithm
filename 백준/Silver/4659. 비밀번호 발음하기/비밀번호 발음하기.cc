#include <bits/stdc++.h>
using namespace std;  

#define prev aaaa

int vcnt, ccnt;
string s;
char prev;
bool vflag, lflag;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    while (1) {
        cin >> s;
        if (s=="end") break;

        prev='0';
        vflag = lflag = false;
        vcnt = ccnt = 0;
        for (char ch:s) {
            if (ch=='a'||ch=='e'||ch=='i'||ch=='o'||ch=='u') {
                vflag = true;
                vcnt++; ccnt=0;
            }
            else ccnt++, vcnt=0;

            if (ch==prev && ch!='e' && ch!='o') {lflag=true; break;}
            if (vcnt>=3 || ccnt >=3) {lflag=true; break;}

            prev=ch;
        }

        if (!vflag || lflag) cout << "<" << s << "> is not acceptable." << '\n';
        else cout << "<" << s << "> is acceptable." << '\n';

    }

    return 0;
}