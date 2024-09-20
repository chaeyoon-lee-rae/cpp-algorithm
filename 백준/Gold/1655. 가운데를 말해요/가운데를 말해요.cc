#include <iostream>
#include <queue>
using namespace std;

const int minN = -10001, maxN = 10001;

bool flag;
int n, mid;
priority_queue<int> pqL;
priority_queue<int, vector<int>, greater<int>> pqR;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    // 홀수 번째
    // - 두 pq의 개수가 안맞으면 pop해서 mid 바꾸기
    // 짝수 번째
    // - 왼쪽 pq의 숫자가 더 크면 pop해서 mid 바꾸기

    cin >> n;
    cin >> mid; cout << mid << "\n";
    int temp;
    for (int i = 0; i < n - 1; ++i) {
        cin >> temp;
        if (temp >= mid) pqR.push(temp);
        else pqL.push(temp);

        // flag == 1 홀수번째
        if (flag && pqL.size() < pqR.size()) {
            pqL.push(mid);
            mid = pqR.top();
            pqR.pop();
        }
        else if (pqL.size() > pqR.size()) {
            pqR.push(mid);
            mid = pqL.top();
            pqL.pop();
        }

        cout << mid << "\n";

        flag ^= 1;
    }

    return 0;
}
