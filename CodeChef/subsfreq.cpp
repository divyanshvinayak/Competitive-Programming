#include <bits/stdc++.h>
using namespace std;

const long long MAXN = 5e5 + 1, MOD = 1e9 + 7;
long long t, n, i, j, k, s, f, g, c, x, z, v, m, h, res, a[MAXN], l[MAXN], fact[MAXN] = {1, 1}, inv[MAXN] = {1, 1}, lazy[MAXN], st[MAXN << 1];
vector<long long> out[MAXN];
bool cl, cr;

void precompute()
{
	for (i = 2; i < MAXN; ++i)
	{
		fact[i] = fact[i - 1] * i % MOD;
		inv[i] = inv[MOD % i] * (MOD - MOD / i) % MOD;
	}
	for (i = 2; i < MAXN; ++i)
		inv[i] = inv[i] * inv[i - 1] % MOD;
}

long long nCr(long long n, long long r)
{
	return fact[n] * inv[n - r] % MOD * inv[r] % MOD;
}

long long power(long long x, long long y)
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

long long inverse(long long q)
{
	return power(q, MOD - 2);
}

long long divide(long long p, long long q)
{
	return inverse(q) * p % MOD;
}

void build()
{
	for (j = m - 1; j; --j)
		st[j] = st[j << 1] * st[j << 1 | 1] % MOD;
}

void calc(long long p, long long k)
{
	if (lazy[p] == 1)
		st[p] = st[p << 1] * st[p << 1 | 1] % MOD;
	else
		st[p] = st[p] * power(lazy[p], k) % MOD;
}

void apply(long long p, long long val, long long k)
{
	st[p] = st[p] * power(val, k) % MOD;
	if (p < m)
		lazy[p] = lazy[p] * val % MOD;
}

void push(long long l, long long r)
{
	s = h;
	k = 1 << (h - 1);
	for (l += m, r += m; s; --s, k >>= 1)
		for (j = l >> s; j <= r >> s; ++j)
			if (lazy[j] != 1)
			{
				apply(j << 1, lazy[j], k);
				apply(j << 1 | 1, lazy[j], k);
				lazy[j] = 1;
			}
}

void update(long long l, long long r, long long val)
{
	push(l, l);
	push(r, r);
	cl = cr = false;
	g = 1;
	for (l += m, r += m + 1; l < r; l >>= 1, r >>= 1, g <<= 1)
	{
		if (cl)
			calc(l - 1, g);
		if (cr)
			calc(r, g);
		if (l & 1)
			apply(l++, val, g), cl = true;
		if (r & 1)
			apply(--r, val, g), cr = true;
	}
	for (--l; r; l >>= 1, r >>= 1, g <<= 1)
	{
		if (cl)
			calc(l, g);
		if (cr && (!cl || l != r))
			calc(r, g);
	}
}

long long query(long long l, long long r)
{
	push(l, l);
	push(r, r);
	res = 1;
	for (l += m, r += m + 1; l < r; l >>= 1, r >>= 1)
	{
		if (l & 1)
			res = res * st[l++] % MOD;
		if (r & 1)
			res = res * st[--r] % MOD;
	}
	return res;
}

void solve()
{
	cin >> n;
	for (i = 1; i <= n; ++i)
		cin >> x, ++a[x];
	m = *max_element(a, a + n) + 1;
	fill(st, st + m * 2, 1);
	fill(lazy, lazy + m, 1);
	h = ceil(log2(m));
	f = 0;
	for (i = 1; i <= n; ++i)
	{
		if (a[i])
		{
			out[i].assign(a[i] + 1, 0);
			x = v = 1;
			if (f)
			{
				for (f = 1; f <= a[i]; ++f)
				{
					z = query(f, f);
					c = nCr(a[i], f);
					v = (v + c) % MOD;
					update(f, f, v);
					out[i][f] = divide(c * x % MOD, v * z % MOD);
					x = z;
				}
				update(f, m, v);
			}
			else
			{
				for (f = 1; f <= a[i]; ++f)
				{
					c = nCr(a[i], f);
					v = (v + c) % MOD;
					out[i][f] = divide(c, v);
					st[m + f] = v;
				}
				build();
				update(f, m, v);
			}
		}
	}
	for (i = 1; i < m; ++i)
		l[i] = query(i, i);
	for (i = 1; i <= n; ++i)
	{
		if (a[i])
		{
			c = 0;
			for (f = 1; f <= a[i]; ++f)
				c = (c + out[i][f] * l[f]) % MOD;
			a[i] = 0;
			cout << c << ' ';
		}
		else
			cout << "0 ";
	}
	cout << '\n';
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