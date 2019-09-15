#include <bits/stdc++.h>
using namespace std;
#define long long long
typedef pair<long, long> pii;

long getLength(long n){
	long haha = 0;
	while (n > 0) n /= 10, haha++;
	return haha;
}

long ans(long n){
	long len = getLength(n);
	long dig[len], haha = 0;
	for(long i = 0; i < len; i++) dig[i] = n % 10, n /= 10;
	for(long i = 0; i < len; i++){
		for(long j = i + 1; j < len; j++){
			if (dig[i] > dig[j]) haha++;
		}
	}
	return haha;
}

int main() {
	ios_base::sync_with_stdio(0);
	long T; cin >> T;
	long answer[1000001] = {};
	for(long i = 1; i < 1000001; i++) answer[i] = answer[i - 1] + ans(i);
	for(long ii = 0; ii < T; ii++){
		long l, r; cin >> l >> r;
		cout << answer[r] - answer[l - 1] << '\n';
	}
}