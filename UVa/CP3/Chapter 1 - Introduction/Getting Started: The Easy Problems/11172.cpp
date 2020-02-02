#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(int argc, char const *argv[])
{
    int t; cin >> t;
    for (int iii = 0; iii < t; iii++)
    {
        int a, b; cin >> a >> b;
        if (a < b) cout << "<\n";
        else if (a ==  b) cout << "=\n";
        else cout << ">\n";
    }
    
    return 0;
}
