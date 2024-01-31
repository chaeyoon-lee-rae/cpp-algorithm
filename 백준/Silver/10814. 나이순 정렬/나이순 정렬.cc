#include <bits/stdc++.h>
using namespace std;  

struct person
{
    int age, order;
    string name;
};

int N;

bool cmp(person a, person b) {
    if (a.age==b.age) return a.order<b.order;
    return a.age<b.age;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;
    vector<person> v(N);
    for (int i=0; i<N; ++i) {
        int age; string name;
        cin >> age >> name;
        v[i].age = age;
        v[i].name = name;
        v[i].order = i;
    }

    sort(v.begin(), v.end(), cmp);
    for (auto it:v) cout << it.age << ' ' << it.name << '\n';

    return 0;
}