#include <bits/stdc++.h>
using namespace std;  

typedef long long ll;
const int INF=1e9+1;
int s, c, l[1000001], lo, hi, ret;
ll sum;

int check(int mid) {
    int cnt=0;
    for (int i=0; i<s; ++i) {
        cnt+=l[i]/mid;
    }
    return cnt;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> s >> c;
    for (int i=0; i<s; ++i) {
        cin >> l[i]; 
        sum+=l[i];
    }

    lo=1, hi=INF;
    while(lo<=hi) {
        int mid = (lo+hi)/2;
        int cnt=check(mid);
        if (cnt>=c) {
            ret=mid;
            lo=mid+1;
        } else hi=mid-1;
    }
    // int 연산, 특히 +, *할 때 overflow되는지 꼭 살펴보기
    cout << sum-(ll)ret*c << '\n'; // ret*c하는 데에서 overflow 생김
    
    // 이렇게 확인하는 것이 번거로우니 먼저 ll으로 다 선언하고 나중에 시간남으면 int로 바꾸도록 하자

    return 0;
}
