#include <bits/stdc++.h>
using namespace std;

#define long long long
#define pair pair<char, long>

#define MAX 1000000

pair letter[MAX];

int main() {
	string s; cin >> s; long len = s.length();
	for (long i = 0; i < len; i++){
		letter[i].first = s[i]; letter[i].second = i;
	}
	sort(letter, letter + len);
	long n; cin >> n;
	for (long iii = 0; iii < n; iii++){
		cin >> s; long candLen = s.length();
		// cout << s;
		long currCandidate = 0; bool ok = true;
		long begin = INT_MAX, end = INT_MIN;
		
		for (long i = 0; i < candLen; i++){
			long left = 0, right = len - 1;
			char curr = s[i];
			if (left == len){
				ok = false; break;
			}
			
			while (left < right){
				long mid = (left + right) / 2;
				if (letter[mid].first < curr) left = mid + 1;
				else if (letter[mid].first == curr && letter[mid].second < currCandidate) left = mid + 1;
				else right = mid;
			}

			if (letter[left].first != curr){
				ok = false; break;
			}
            if (letter[left].second < currCandidate){
				ok = false; break;
			}

			currCandidate = letter[left].second;
			begin = min(begin, currCandidate);
			end = max(end, currCandidate);
			currCandidate++;
		}
		// cout << "ffdsfsf";
		if (ok)
			cout << "Matched " << begin << ' ' << end << '\n';
		else cout << "Not matched\n";
	}
}
