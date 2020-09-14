#include <bits/stdc++.h>
using namespace std;

const long long MAXN = 1e5 + 1, MOD = 1e9 + 7;
long long t, n, m, k, r, i, cards[MAXN], fact[MAXN] = {1, 1}, inv[MAXN] = {1, 1}, pow2[MAXN] = {1, 2};

void precompute()
{
    for (i = 2; i < MAXN; ++i)
    {
        fact[i] = fact[i - 1] * i % MOD;
        inv[i] = inv[MOD % i] * (MOD - MOD / i) % MOD;
        pow2[i] = pow2[i - 1] * 2 % MOD;
    }
    for (i = 2; i < MAXN; ++i)
        inv[i] = inv[i - 1] * inv[i] % MOD;
}

long long nCr(long long n, long long r)
{
    return fact[n] * inv[n - r] % MOD * inv[r] % MOD;
}

void solve()
{
    cin >> n;
    for (i = 0; i < n; ++i)
        cin >> cards[i];
    m = *max_element(cards, cards + n);
    k = 0;
    for (i = 0; i < n; ++i)
        if (cards[i] == m)
            ++k;
    if (k & 1)
        cout << pow2[n] << '\n';
    else
        cout << (MOD + pow2[n] - pow2[n - k] * nCr(k, k / 2) % MOD) % MOD << '\n';
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    precompute();
    cin >> t;
    while (t--)
        solve();
    return 0;
}