#include <bits/stdc++.h>
using namespace std;  

int N, ret;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;
    for (int i=1; i<N; ++i) {
        int sum=i; int num=i;
        while(num%10) {
            sum+=num%10;
            num/=10;
        }
        if (sum==N) {
            ret = i; break;
        }
    }
    cout << ret << '\n';

    return 0;
}
