#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
bitset<1000001> bs, border;

bool setTime(int begin, int end){
	if (border[begin] == false && bs[begin] == true) return false;
	if (border[end] == false && bs[end] == true) return false;
	
	border[begin] = bs[begin] = border[end] = bs[end] = true;
	for (int i = begin + 1; i < end; i++){
		if (bs[i]) return false;
		bs[i] = true;
	}
	return true;
}

int main() {
	int n, m;
	while (true){
		cin >> n >> m;
		if (n == 0 && m == 0) break;
		bool ok = true;
		for (int ii = 0; ii < n; ii++){
			int begin, end; cin >> begin >> end;
			if (!setTime(begin, end)){
				ok = false; break;
			}
		}
		if (!ok) goto xyz;
		for (int ii = 0; ii < m; ii++){
			int begin, end, interval; cin >> begin >> end >> interval;
			for (int b = begin, e = end; e <= 1000000; b += interval, e += interval){
				if (!setTime(b, e)){ok = false; break;}
			}
			if (!ok) goto xyz;
		}
		//
		xyz:
		if (ok) cout << "NO ";
		cout << "CONFLICT\n";
		bs &= 0, border &= 0;
	}
}
