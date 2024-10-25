#include <iostream>
#include <cstring>
#include <string>
using namespace std;

const int mod = 1000000;
int n, dp[5001];
string str;

int go(int idx) {
    if (idx == n) return 1;

    int& ret = dp[idx];
    if (~ret) return ret;

    ret = 0;
    if (idx + 1 < n) {
        int a = str[idx] - '0';
        int b = str[idx + 1] - '0';
        if (a != 0 && a * 10 + b <= 26)
            ret = (ret + go(idx + 2)) % mod;
    }
    if (str[idx] != '0')
        ret = (ret + go(idx + 1)) % mod;

    return ret;
}

int main() {
    memset(dp, -1, sizeof(dp));

    cin >> str;
    n = str.size();

    cout << go(0) << "\n";

    return 0;
}
