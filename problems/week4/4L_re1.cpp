#include <bits/stdc++.h>
using namespace std;  

int T, temp, num;
string funcS, s;
bool flipped, flag;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> T;
    while(T--) {
        deque<int> dq;
        cin >> funcS >> temp >> s;
        num=0;
        for (char ch:s) {
            if (ch<='9'&&ch>='0') {
                num=num*10+(ch-'0');
            } else if (ch==',') {
                dq.push_back(num);
                num=0;
            }
        }
        if (num) dq.push_back(num); 

        flipped=0; flag=0;
        for (char ch:funcS) {
            if (ch=='D') {
                if (dq.empty()) {
                    cout << "error" << '\n';
                    flag=1;
                    break;
                }
                if (flipped) dq.pop_back();
                else dq.pop_front();
            }
            else flipped^=1;
        }

        if (flag) continue; // 여기서 프린트 해주기
        cout << '[';
        if (flipped) {
            while (dq.size()>1) { // 따로 구현할 필요없이 reverse 적용
                cout << dq.back() << ',';
                dq.pop_back();
            }
            if (dq.size()) cout << dq.back();
            cout << ']' << '\n';;
        } else {
            while (dq.size()>1) {
                cout << dq.front() << ',';
                dq.pop_front();
            }
            if (dq.size()) cout << dq.front();
            cout << ']' << '\n';;
        }
    }

    return 0;
}
