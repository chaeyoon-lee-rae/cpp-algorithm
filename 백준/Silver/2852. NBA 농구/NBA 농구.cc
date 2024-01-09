#include <bits/stdc++.h>
using namespace std;  

int N, temp, pt1, pt2, s1, s2, pre;
int t[104], sec[104];
string s, tempm, temps;

void printRet(int sec) {
    if (sec/60 < 10) cout << 0 << sec/60;
    else cout << sec/60;
    cout << ":";
    if (sec%60 < 10) cout << 0 << sec%60;
    else cout << sec%60;
    cout << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;
    for (int i=0; i<N; i++) {
        cin >> t[i] >> s;
        tempm=temps="";
        for (int i=0; i<s.size(); i++) {
            if (i==0 || i==1) tempm.push_back(s[i]);
            if (i==3 || i==4) temps.push_back(s[i]);
        }
        temp = stoi(tempm) * 60 + stoi(temps);
        sec[i] = temp;
    }

    t[N] = 0;
    sec[N] = 48*60;

    for (int i=0; i<N+1; i++) {
        if (i>=1) {
            if (pt1>pt2) s1 += sec[i] - sec[pre];
            else if (pt2>pt1) s2 += sec[i] - sec[pre];
        }

        if (t[i]==1) pt1++;
        else if (t[i]==2) pt2++;

        pre = i;
    }

    printRet(s1);
    printRet(s2);

    return 0;
}