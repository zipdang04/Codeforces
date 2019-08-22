#include <bits/stdc++.h>
using namespace std;

#define long long long
#define pair pair<long, long>

#define x first
#define y second

#define MAX 1000000

long sqr(long n){return n * n;}

double length(pair a, pair b){
	return sqrt(sqr(a.x - b.x) + sqr(a.y - b.y));
}

main() {
	long T; cin >> T;
	for (long iiii = 0; iiii < T; iiii++)
	{
		long n; cin >> n;
		pair point[n];
		for (long i = 0; i < n; i++)
			cin >> point[i].x >> point[i].y;
		sort(point, point + n);

		long queue[n]; 
		long len = 0, currY = 0;
		queue[len++] = n - 1;
		for (long i = n - 2; i >= 0; i--)
			if (point[i].y > currY){
				currY = point[i].y;
				queue[len++] = i;
			}

		double ans = 0; pair prev = point[n - 1];
		for (long i = 1; i < len; i++)
		{
			pair curr = point[queue[i]];

			if (queue[i - 1] - queue[i] == 1){
				ans += length(prev, curr);
			}
			else{
				pair right = point[queue[i] + 1];
				double save = length(curr, right);
				long tuso = curr.y - prev.y, mauso = curr.y - right.y;
				save = save * (double)tuso / (double)mauso;
				ans += save;
			}
			prev = curr;
		}
		printf("%0.2f\n", ans);
	}
	
}
