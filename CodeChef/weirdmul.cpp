#include <bits/stdc++.h>
using namespace std;

const long long MOD = 998244353;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    long long t, n, x, a, b, p, q, y, z, i;
    cin >> t;
    while(t--)
    {
        cin >> n >> x;
        vector<long long> c(n);
        for (i = 0; i < n; ++i)
            cin >> c[i];
        a = (c[0] * c[0]) % MOD, b = a, q = x, y = 1, z = 1 + x, p = 1;
        for (i = 0; i < n; ++i)
            p = (((a * y) % MOD) * p) % MOD, a = (a * b) % MOD, y = (((z * z) % MOD) * y) % MOD, q = (q * x) % MOD, z = (q + z) % MOD;
        cout << p << '\n';
    }
    return 0;
}