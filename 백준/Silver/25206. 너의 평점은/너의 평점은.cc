#include <bits/stdc++.h>
using namespace std;  

float credit, score, tot_credit, tot_score;
string s, grade;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    for (int i=0; i<20; ++i) {
        cin >> s >> credit >> grade;
        if (grade=="A+") score=4.5f;
        else if (grade=="A0") score=4.0f;
        else if (grade=="B+") score=3.5f;
        else if (grade=="B0") score=3.0f;
        else if (grade=="C+") score=2.5f;
        else if (grade=="C0") score=2.0f;
        else if (grade=="D+") score=1.5f;
        else if (grade=="D0") score=1.0f;
        else if (grade=="F") score=0.0f;
        else continue;

        tot_credit += credit;
        tot_score += score*credit;
    }
    cout << fixed;
    cout.precision(6);
    cout << tot_score/tot_credit << '\n';

    return 0;
}