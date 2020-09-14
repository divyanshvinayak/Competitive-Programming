#include <bits/stdc++.h>
using namespace std;

long long t, n, m, s, z, c;

void solve()
{
	cin >> n;
	s = (n * (n + 1)) >> 1;
	if (s & 1)
	{
		cout << "0\n";
		return;
	}
	c = 0;
	m = (-1 + sqrtl(1 + (s << 2))) / 2;
	if (m * (m + 1) == s)
		c += m * (m - n) + s - n, --m;
	z = (s - m * (m + 1)) >> 1;
	if (z < n)
		c += min(m, min(n - m, min(z, n - z))), z += m;
	if (z < n)
		c += min(m, min(n - m, min(z, n - z)));
	cout << c << '\n';
}

int main()
{
	ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> t;
	while (t--)
        solve();
    return 0;
}