#include <bits/stdc++.h>
using namespace std;  

int t, cnt; 
char str[100001];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    scanf("%d", &t);
    while(t--) {
        stack<char> stk;
        scanf("%s", str);
        int len = strlen(str);
        for (int i=0; i<len; ++i) {
            if (stk.size()&&stk.top()==str[i])
                stk.pop();
            else stk.push(str[i]);
        }
        if (stk.empty()) ++cnt;
    }
    printf("%d\n", cnt);

    return 0;
}
