#include <bits/stdc++.h>
using namespace std;  

#define MAX 200000
int n, k, vis[MAX+1], preIdx[MAX+1];
queue<int> q;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> k;
	if (n==k) {
		cout << 0 << '\n';
		cout << n << '\n';
		return 0;
	}
	
	memset(preIdx, -1, sizeof(preIdx));

	q.push(n);
	vis[n]=1;
	while(q.size()) {
		int x = q.front();
		q.pop();

		for (int nx : {x-1, x+1, x*2}) {
			if (nx<0||nx>=MAX||vis[nx]) continue;
			vis[nx] = vis[x]+1;
			preIdx[nx] = x;
			q.push(nx);
		}
	}

	cout << vis[k] - 1 << '\n';

	vector<int> idx; 
	int i=k;
	while(preIdx[i]!=-1) {
		idx.push_back(preIdx[i]);
		i = preIdx[i];
	}
	reverse(idx.begin(), idx.end());
	for (int i : idx) cout << i << " ";
	cout << k << '\n';

	return 0;
}
