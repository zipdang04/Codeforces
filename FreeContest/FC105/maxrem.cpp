#include <bits/stdc++.h>
using namespace std;
int main(int argc, char const *argv[])
{
    int n; cin >> n;
    {
        if (n == 1){
            cout << 0; return 0;
        }
    }
    int a[n]; for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    sort(a, a + n);
    int i = n - 2;
    while (i > 0 && a[i] == a[n - 1]) i--;
    cout << a[i] % a[n - 1];
    return 0;
}
