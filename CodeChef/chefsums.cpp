#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const ll MAX = 1e6 + 1, MOD = 1e9 + 7;
ll i, j, n, k, m, x, c, res, a[MAX], spf[MAX], powerx[MAX], powerm[MAX];

ll power(ll x, ll y)
{
    res = 1;
    while (y)
    {
        if (y & 1)
            res = res * x % MOD;
        y >>= 1;
        x = x * x % MOD;
    }
    return res;
}

void precompute()
{
    fill(spf, spf + MAX, 2);
    for (i = 3; i < MAX; i += 2)
        spf[i] = i;
    for (i = 3; i < sqrtl(MAX); i += 2)
        if (spf[i] == i)
            for (j = i * i; j < MAX; j += i)
                if (spf[j] == j)
                    spf[j] = i;
    for (i = 0; i < n; ++i)
    {
        powerx[i] = power(a[i], x);
        powerm[i] = power(a[i], m);
    }
}

void product(ll idx, ll g, ll s, ll p, ll w)
{
    for (ll i = 0; i < n; ++i)
    {
        if (idx < k)
            product(idx + 1, __gcd(g, a[i]), (s + powerx[i]) % MOD, p * powerm[i] % MOD, min(w, spf[a[i]]));
        else
        {
            c = (c + g * s % MOD * p % MOD * w % MOD) % MOD;
            return;
        }
    }
}

void solve()
{
    cin >> n >> k >> m >> x;
    for (i = 0; i < n; ++i)
        cin >> a[i];
    precompute();
    for (i = 0; i < n; ++i)
        product(1, a[i], powerx[i], powerm[i], spf[a[i]]);
    cout << c << '\n';
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}