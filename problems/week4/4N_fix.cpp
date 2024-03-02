/*=========================================

▶️ 제목: 큰 수 A+B (2)
▶️ 풀이 여부: ✅
▶️ 풀이 시간: 20분
▶️ 풀이 참고: O

=========================================*/

#include <bits/stdc++.h>
using namespace std;  

string a, b, ret;
int sum;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> a >> b;
    while (a.size() || b.size() || sum) {
        if (a.size()) {
            sum += a.back()-'0';
            a.pop_back();
        }
        if (b.size()) {
            sum += b.back()-'0';
            b.pop_back();
        }
        ret += (sum%10) + '0';
        sum /= 10;
    }
    reverse(ret.begin(), ret.end());

    cout << ret << '\n';

    return 0;
}