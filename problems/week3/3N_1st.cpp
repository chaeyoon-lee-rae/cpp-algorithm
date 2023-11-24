/*=========================================

▶️ 제목: 완전이진트리
▶️ 풀이 여부: ✅
▶️ 풀이 시간: 50분
▶️ 풀이 참고: O

- [중위순회, 전위순회, 후위순회] 개념 익히기
- 구간을 쪼개서 재귀함수 돌릴 때에는 start≤end를 가정하므로 그에 반하는 경우의 수는 제외시킨다.
- vector로 레벨화 시켜서 참조만으로 레벨별 요소들을 구분할 수 있다. -> 굳이 queue를 쓸 필요가 없다!

=========================================*/

#include <bits/stdc++.h>
using namespace std;  

int temp, k, arr[1050], start, last;
queue<pair<int,int>> q;
vector<int> v;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> k;
    int len = (int)pow(2, k) - 1;   // 요소의 총 개수를 계산
    for (int i=0; i<len; ++i) {
        cin >> arr[i];
    }

    q.push({0,len-1});
    while (q.size()) {      // queue말고 벡터만으로 구현하기
        tie(start, last) = q.front();
        q.pop();
        if (start==last) {v.push_back(arr[start]); continue;}
        int mid = (start + last)/2;
        v.push_back(arr[mid]);
        q.push({start,mid-1});
        q.push({mid+1,last});
    }

    int n = 0;
    for (int i=0; i<k; ++i) {
        for (int j=0; j<pow(2,i); ++j) {
            cout << v[n] << " ";
            ++n;
        }
        cout << '\n';
    }

    return 0;
}