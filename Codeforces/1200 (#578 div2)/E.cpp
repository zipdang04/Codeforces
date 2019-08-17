#include <bits/stdc++.h>
using namespace std;
#define long long long
#define MOD 1000000009
#define MAX 100000
#define BASE 809

vector<long> hashCode[MAX];
vector<long> hashMain;
string s[MAX];
long multiplier[1000001] = {};

long n;

void init(){
	multiplier[0] = 1;
	for(int i = 1; i <= MAX; i++)
		multiplier[i] = (multiplier[i - 1] * BASE) % MOD;
}

void hashStr(long index){
	string currS = s[index]; int len = currS.length();
	for(int i = 0; i < len; i++){
		long save = (currS[i] * multiplier[i]) % MOD;
		if (i > 0) save += hashCode[index][i - 1], save %= MOD;
		hashCode[index].push_back(save);
	}
}

void findSame(long index){
	vector<long> curr = hashCode[index];
	long start = hashMain.size() - min(hashMain.size(), curr.size());
	
}

int main() {
	init();
	cin >> n;
	for(long i = 0; i < n; i++) {
		cin >> s[i]; hashStr(i);
		for(long j: hashCode[i]) cout << j << ' ';
		cout << endl;
	}
	cout << s[0]; hashMain = hashCode[0];
	for(long i = 1; i < n; i++) findSame(i);
}
