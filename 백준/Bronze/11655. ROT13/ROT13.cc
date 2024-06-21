#include <bits/stdc++.h>
using namespace std;  

char s[101];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin.getline(s, 101);
    int length = strlen(s);
    for (int i=0; i<length; ++i) {
        if (s[i]>='A'&&s[i]<='Z') {
            s[i]=((s[i]-'A')+13)%26 + 'A';
        } else if (s[i]>='a'&&s[i]<='z') {
            s[i]=((s[i]-'a')+13)%26 + 'a';
        }
    }
    cout << s << endl;

    return 0;
}
