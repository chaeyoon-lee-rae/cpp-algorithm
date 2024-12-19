#include <iostream>
#include <string>
using namespace std;

int a[] = { 6,2,5,5,4,5,6,3,7,6 }, n;
string dpMin[101], maxStr(51, '1');

string compMin(string a, string b) {
    if (a.size() == b.size()) return (a < b ? a : b);
    if (a.size() < b.size()) return a;
    else return b;
}

void calcDPMin() {
    for (int i = 2; i <= 100; ++i) {
        for (int j = 0; j <= 9; ++j) {
            if (i - a[j] < 0) continue;
            if (j == 0 && dpMin[i - a[j]] == "") continue;

            dpMin[i] = compMin(dpMin[i], dpMin[i - a[j]] + to_string(j));
        }
    }
}

string calcMax(int num) {
    string ret = "";
    if (num & 1) {
        ret += "7";
        num -= 3;
    }
    while (num) {
        ret += "1";
        num -= 2;
    }
    return ret;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    fill(dpMin, dpMin + 101, maxStr);
    dpMin[0] = "";
    calcDPMin();

    cin >> n;
    int num;
    while (n--) {
        cin >> num;
        cout << dpMin[num] << " " << calcMax(num) << "\n";
    }

    return 0;
}
