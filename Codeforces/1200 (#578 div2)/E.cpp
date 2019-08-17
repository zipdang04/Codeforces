#include <bits/stdc++.h>
using namespace std;

#define long long long

#define MOD 1000000009
#define MAX 100000
#define BASE 809

vector<long> hashCode[MAX];
vector<long> hashMain;
string s[MAX], ans;
long multiplier[1000001] = {};

long n;

void init(){
	multiplier[0] = 1;
	for(long i = 1; i <= MAX; i++)
		multiplier[i] = (multiplier[i - 1] * BASE) % MOD;
}

void hashStr(long index){
	string currS = s[index]; long len = currS.length();

	for(long i = 0; i < len; i++){
		long save = (currS[i] * multiplier[i]) % MOD;
		if (i > 0) save += hashCode[index][i - 1], save %= MOD;
		hashCode[index].push_back(save);
	}
}

void findSame(long index){
	vector<long> curr = hashCode[index];
	long attach = min(hashMain.size(), curr.size()), start = hashMain.size() - attach;
	long len = hashMain.size();

	for(long i = start; i <= len; i++){
		long left, right;
		if (i < len){
			left = (hashMain[len - 1] - hashMain[i - 1] + MOD) % MOD;
			right = (curr[attach - 1] * multiplier[i]) % MOD;
		}
		if (i == len || left == right){
			long nextLen = s[index].length();
			for(long j = attach; j < nextLen; j++){
				char c = s[index][j];
				ans += c;
				long save = (c * multiplier[len]) % MOD + hashMain[len - 1]; save %= MOD;
				len++, hashMain.push_back(save);
			}
			return;
		}

		attach--;
	}
}

int main() {
	init();
	cin >> n;
	for(long i = 0; i < n; i++) {
		cin >> s[i]; hashStr(i);
	}

	hashMain = hashCode[0]; ans = s[0];
	for(long i = 1; i < n; i++) findSame(i);
	
	cout << ans;
}
