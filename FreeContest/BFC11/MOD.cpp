#include <bits/stdc++.h>
using namespace std;
int main(int argc, char const *argv[])
{
    int n; cin >> n;
    cout << abs(n / 100) % 10 << abs(n / 10) % 10 << abs(n) % 10;
    
    return 0;
}
