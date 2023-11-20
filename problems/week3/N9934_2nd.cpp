/*=========================================

▶️ 제목: 완전이진트리
▶️ 풀이 여부: ✅
▶️ 풀이 시간: 50분
▶️ 풀이 참고: O

선생님 해설보고 재풀이

=========================================*/

#include <bits/stdc++.h>
using namespace std;  

int temp, k, arr[1050];
vector<int> v[14];

void go(int s, int e, int level) {
    if (s>e) return;
    if (s==e) {v[level].push_back(arr[s]); return;}
    int mid = (s + e)/2;
    v[level].push_back(arr[mid]);
    go(s, mid-1, level+1);
    go(mid+1, e, level+1);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> k;
    int len = (int)pow(2, k) - 1; 
    for (int i=0; i<len; ++i) {
        cin >> arr[i];
    }

    go(0, len-1, 0);

    for (int i=0; i<k; ++i) {
        for (int it : v[i]) cout << it << " ";
        cout << '\n';
    }

    return 0;
}