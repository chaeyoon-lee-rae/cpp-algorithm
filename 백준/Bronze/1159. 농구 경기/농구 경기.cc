#include <bits/stdc++.h>
using namespace std;  

int num;
int arr[26];
string name;
string ret;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> num;
    for (int i=0; i<num; ++i) {
        cin >> name;
        arr[name[0] - 'a']++;
    }

    for (int i=0; i<26; ++i) {
        if (arr[i] >= 5) {
            ret += (char)(i + 'a');
        }
    }

    if (ret.size() == 0) cout << "PREDAJA" << '\n';
    else cout << ret << '\n';

}
