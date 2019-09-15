#include <bits/stdc++.h>
using namespace std;
#define long long long
int main() {
	long n; cin >> n;
	long a[n];
	for (long i = 0; i < n; i++){
		cin >> a[i];
	}
	sort(a, a + n);
	long ans = 0;
	for (long i = 0; i < n; i++){
		if (i % 2) ans += a[i];
		else ans -= a[i];
	}
	cout << abs(ans);
}