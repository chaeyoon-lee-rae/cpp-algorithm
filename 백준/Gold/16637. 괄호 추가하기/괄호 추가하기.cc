#include <bits/stdc++.h>
using namespace std;  

const int INF=-1e9;
int N, ret=INF; char ch;
vector<int> num;
vector<char> oper;

int calc(int idx, int num1, int num2) {
    if (oper[idx]=='+') return num1+num2;
    if (oper[idx]=='-') return num1-num2;
    if (oper[idx]=='*') return num1*num2;
    return 0;
}

void go(int here, int sum) {
    if (here==num.size()-1) {ret=max(ret,sum); return;}

    go(here+1, calc(here,sum,num[here+1]));
    if (here+2 <= num.size()-1) {
        int temp=calc(here+1,num[here+1],num[here+2]);
        go(here+2, calc(here,sum,temp));
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;
    for (int i=0; i<N; ++i) {
        cin >> ch;
        if (i%2==0) num.push_back(ch-'0');
        if (i%2==1) oper.push_back(ch);
    }

    go(0, num[0]);

    cout << ret << '\n';

    return 0;
}