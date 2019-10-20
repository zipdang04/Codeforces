#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    ll R, G, B, n; cin >> R >> G >> B >> n;
    stack<ll> st;
    while (n > 1){
        st.push(n % 3); n = ++n / 3;
    }
    while (!st.empty()){
        ll co = st.top(); st.pop();
        if (co == 2){
            ll newR = R + G, newG = B, newB = G;
            R = newR, G = newG, B = newB;
        }
        else if (co == 0){
            ll newR = B, newG = G + B, newB = R;
            R = newR, G = newG, B = newB;
        }
        else {
            ll newR = G, newG = R, newB = B + R;
            R = newR, G = newG, B = newB;
        }
    }
    cout << R << ' ' << G << ' ' << B;
    return 0;
}
