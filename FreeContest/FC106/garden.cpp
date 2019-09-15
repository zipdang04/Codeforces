#include <bits/stdc++.h>
using namespace std;
#define long long long
typedef pair<long, long> pii;
int main() {
	long n, l; cin >> n >> l;
	priority_queue<pii, vector<pii>, greater<pii> > pq;
	long b[n];
	for (long i = 0; i < n; i++){
		long a, bb; cin >> a >> bb;
		pq.push(pii(a, i)); b[i] = bb;
	}
	while (l > 0){
		pii curr = pq.top(); pq.pop();
		curr.first += b[curr.second];
		pq.push(curr);
		l--;
	}
	cout << pq.top().first;
}