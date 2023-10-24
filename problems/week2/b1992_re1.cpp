/*=========================================

▶️ 제목: 쿼드트리
▶️ 풀이 여부: ❌
▶️ 풀이 시간: 30분
▶️ 풀이 참고: X

로직은 같지만 매개변수가 변경된다? 그러면 재귀함수를 사용해보도록 하자!

분할정복 (Divide & Conquer)
- 어떠한 문제를 하위로 나누어서 해결하는 방법론 
- 보통 재귀함수 또는 스택을 사용

=========================================*/


#include <bits/stdc++.h>
using namespace std;  

int N;
char a[68][68];
string s, ret;

string go(int y, int x, int size) {     // size 넘겨주기
    if (size==1) return string(1, a[y][x]);     // char를 string으로 바꾸는 법

    string str="";
    char ch = a[y][x];
    for (int i=y; i<y+size; i++) {
        for (int j=x; j<x+size; j++) {
            if (ch!=a[i][j]) {
                str += "(";
                str += go(y, x, size/2);
                str += go(y, x+size/2, size/2);
                str += go(y+size/2, x, size/2);
                str += go(y+size/2, x+size/2, size/2);
                str += ")";
                return str;
            }
        }
    }

    return string(1, a[y][x]);  // 1 - number of times to repeat, char - character to repeat
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;
    for (int i=0; i<N; i++) {
        cin >> s;
        for (int j=0; j<N; j++) {
            a[i][j] = s[j];
        }
    }

    cout << go(0, 0, N) << '\n';

    return 0;
}