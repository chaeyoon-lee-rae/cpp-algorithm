/*=========================================

▶️ 제목: 영역 구하기
▶️ 풀이 여부: ✅
▶️ 풀이 시간: 17분
▶️ 풀이 참고: X

2차원 배열에 fill 함수 사용할 때 주의할 것!

In C++, a two-dimensional array is essentially an array of arrays. So when you declare a 2D array as `int a[100][100]`, 
you're essentially declaring an array of 100 arrays, each of which has 100 `int`s.

When you use an array name without an index (e.g., `a` in your case), it decays to a pointer to its first element. 
But what's the first element of `a`? The first element of `a` is actually the first 1D array, 
i.e., `a[0]`. So, `a` would decay to a pointer to the first 1D array, which has a type of `int(*)[100]`, not `int*`.

On the other hand, when you use `&a[0][0]`, you're getting the address of the very first integer in the 2D array. 
This is equivalent to a pointer of type `int*`.

That's why when using `std::fill()`, you need to use the form:

```cpp
fill(&a[0][0], &a[0][0]+100*100, 0);
```

This accurately gets the starting and ending points for the block of memory you want to fill, treating it as a contiguous block of `int`s.

If you use `fill(a, a+100*100, 0)`, the compiler will give you an error because `a` decays to `int(*)[100]` 
and you can't add `int(*)[100]` and `100*100` directly, as it doesn't make sense semantically in terms of types and memory layout.

즉, 2차원 배열에 a는 pointer to the first element이기에 int(*)[100] type을 가지고 있다. 그래서 포인터 연산이 불가하다.

=========================================*/


#include <bits/stdc++.h>
using namespace std;  

#define y1 aaaa

int N, M, K, a[104][104], x1, y1, x2, y2, cnt1;
bool visited[104][104];
int dy[] = {0, -1, 0, 1};
int dx[] = {1, 0, -1, 0};
vector<int> v;

int go(int y, int x) {
    visited[y][x] =1;
    int cnt = 1;

    for (int i=0; i<4; i++) {
        int ny = y + dy[i];
        int nx = x + dx[i];

        if (ny<0||ny>=N||nx<0||nx>=M) continue;
        if (a[ny][nx] && !visited[ny][nx]) cnt += go(ny, nx);
    }
    
    return cnt;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    fill(&a[0][0], &a[0][0]+104*104, 1);

    cin >> N >> M >> K;
    while (K--) {
        cin >> x1 >> y1 >> x2 >> y2;
        for (int i=y1; i<y2; i++) {
            for (int j=x1; j<x2; j++) {
                a[i][j] = 0;
            }
        }
    }

    for (int i=0; i<N; i++) {
        for (int j=0; j<M; j++) {
            if (a[i][j] && !visited[i][j]) v.push_back(go(i,j)), cnt1++;
        }
    }

    sort(v.begin(), v.end());

    cout << cnt1 << '\n';
    for (int val : v) cout << val << " ";


    return 0;
}