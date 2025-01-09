#include <iostream>
#include <stack>
using namespace std;

const int INF = int(1e6);
int n, a[100001], minBuild[100001], numBuild[100001];
stack<int> stk;

void go(const int& idx) {
    while (stk.size() && a[stk.top()] <= a[idx])
        stk.pop();

    if (stk.empty()) {
        stk.push(idx);
        return;
    }

    if (abs(stk.top() - idx) < abs(minBuild[idx] - idx))
        minBuild[idx] = stk.top();
    else minBuild[idx] = min(minBuild[idx], stk.top());
    numBuild[idx] += stk.size();
    stk.push(idx);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n;
    for (int i = 0; i < n; ++i)
        cin >> a[i];

    fill(minBuild, minBuild + 100001, INF);

    for (int i = 0; i < n; ++i) {
        go(i);
    }

    stk = stack<int>();
    for (int i = n - 1; i >= 0; --i) {
        go(i);
    }

    for (int i = 0; i < n; ++i) {
        cout << numBuild[i] << " ";
        if (numBuild[i]) cout << (minBuild[i] + 1);
        cout << "\n";
    }

    return 0;
}
