#include <bits/stdc++.h>
using namespace std;

#define MAX 100001

typedef pair<int, int> pii;

int n;
pii seg[MAX];
int ans = 0;

void test(int index, pii curr, int numOfSeg){
	ans += numOfSeg;
	if (index == n) return;
	for (int i = index + 1; i <= n; i++){
		if (seg[i].first < curr.second) test(i, pii(curr.first, max(curr.second, seg[i].second)), numOfSeg);
		else test(i, seg[i], numOfSeg + 1);
	}
}

main(){
	freopen("help.in", "r", stdin);
	freopen("help.out", "w", stdout);
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	cin >> n;
	for (int i = 1; i <= n; i++){
		cin >> seg[i].first >> seg[i].second;
	}
	sort(seg + 1, seg + 1 + n);
	for (int i = 1; i <= n; i++){
		test(i, seg[i], 1);
	}
	cout << ans;
}

