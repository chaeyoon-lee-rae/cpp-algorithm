#include <iostream>
#include <algorithm>
#include <limits>
using namespace std;

int liq[100001], n, l, r, sum = numeric_limits<int>::max(), retl, retr;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n;
    for (int i = 0; i < n; ++i)
        cin >> liq[i];
    
    l = 0, r = n - 1;
    while (l < r) {
        int temp = liq[l] + liq[r];
        if (abs(temp) < sum) {
            retl = l;
            retr = r;
            sum = abs(temp);
        }
        if (temp > 0) --r;
        else if (temp < 0) ++l;
        else break;
    }

    cout << liq[retl] << " " << liq[retr] << "\n";
    

    return 0;
}
