#include <bits/stdc++.h>
using namespace std;
int main(int argc, char const *argv[])
{
    int mul, seed, add, mod; 
    int index = 0;
    while (true){
        cin >> mul >> add >> mod >> seed;
        if (!(mul || seed || add || mod)) break;
        int seq[mod << 1]; seq[0] = seed;
        for (int i = 1; i < (mod << 1); i++)
            seq[i] = (seq[i - 1] * mul + add) % mod;
        
        int hare = 2, tor = 1;
        while (seq[hare] != seq[tor]) hare += 2, tor++;
        int cycle = hare - tor; hare = 0;
        while (seq[hare] != seq[tor]) hare++, tor++;
        tor = hare + 1;
        while (seq[hare] != seq[tor]) tor++;
        cout << "Case " << ++index << ": " << tor - hare << '\n';
    }
    return 0;
}
